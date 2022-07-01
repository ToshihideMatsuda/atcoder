#include <bits/stdc++.h> 
#include <unordered_map> 
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define max(a,b)   (a>b?a:b)
#define max3(a,b,c) max(a,max(b,c))
#define min(a,b)   (a<b?a:b)
#define min3(a,b,c) min(a,min(b,c))


#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 15*10000+5

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}

vector<ll> G[MAX_N];


void solve() {
    ll N,M; cin >> N >> M;
    rep(i,M) {
        ll a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    ll q; cin >> q;
    rep(_,q) {
        ll x, k;
        cin >> x >> k;

        set<ll> S;
        queue<pair<ll,ll > > Q;
        Q.push(make_pair(x, k));
        while(Q.size() > 0) {
            auto p = Q.front();Q.pop();
            ll xx = p.first, kk = p.second;
            S.insert(xx);

            if(kk > 0) {
              for(ll z : G[xx]) {
                if(S.count(z)) continue;
                Q.push(make_pair(z, kk -1));
              }
            }
        }

        ll ans = 0;
        for(ll s : S) {
            ans += s;
        }

        cout << ans << endl;
    }


}


int main()
{
  solve();
	return 0;
}