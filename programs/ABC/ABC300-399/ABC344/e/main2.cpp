#include <bits/stdc++.h>
#include <atcoder/all>

using namespace atcoder;
using namespace std;

typedef long long ll;

#define rep(i,n) for(ll i = 0; i < n; i++ )
#define reps(i,m,n) for(ll i = m; i < n; i++ )
#define rev(i,n) for(ll i = n; i > -1; i--)
#define revs(i,m,n) for(ll i = m; i > n; i--)
#define MAX(a,b) (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b) (a<b?a:b)
#define MIN3(a,b,c) MIN(a,MIN(b,c))
#define out0(s) cout << s;
#define out(s) cout << s << endl;
#define outd(s) cout << setprecision(15) << s << endl;
#define pb(s) pushback(s)

int main() {

	vector<tuple<ll,ll,ll>> list(4*100000 + 5);
	list[0] = {-1,1,-1};

	map<ll, vector<ll>> mp;
	ll N; cin >> N;

    rep(i, N) {
        ll a; cin >> a;

		tuple<ll,ll,ll> A = {a, i+2, i};
		list[i+1] = A;

		mp[a].push_back(i+1);
    }

	ll index = N+1; // N+1~

	auto [a,n,b] = list[N];
	list[N] = {a,-1,b};


	ll id = N+1;

    ll Q; cin >> Q;
    rep(i, Q) {
        ll t; cin >> t;
        if (t == 1) {
            ll x, y; cin >> x >> y;
            for (auto i : mp[x]) {
				auto [a, n, b]  = list[i];
				
				list[id] = {y, n, i};;
				list[i] = {a, id, b};
				if(n >= 0) {
					auto [na,nn,nb] = list[n];
					list[n] = {na, nn ,id};
				}

				mp[y].insert(id);
				id++;
            }
        }
        else {
            ll x; cin >> x;
            for (auto i : mp[x]) {
				auto [a, n, b]  = list[i];

                if(b >= 0) {
					auto [ba, bn, bb]  = list[b];
					list[b] = {ba, n, bb};
				}

                if(n >= 0) {
					auto [na, nn, nb]  = list[n];
					list[n] = {na, nn, b};
				}

            }
            mp.erase(x);
        }
    }

    auto [_, _n, __] = list[0]; // ダミーノードの次から開始
	ll p = _n;
    while (p >= 0) {
		auto [a, n, b]  = list[p];
        out0(a); out0(" ");
		p = n;
    }

    return 0;
}