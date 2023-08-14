#include <bits/stdc++.h> 
#include <atcoder/all>
using namespace atcoder;
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) MIN(a,MIN(b,c))
#define out0(s) cout << s;
#define out(s) out1(s)
#define out1(s) cout << s << endl;
#define out2(s,t) cout << s << t << endl;
#define out3(s,t,r) cout << s << t << r << endl;
#define out4(s,t,r,u) cout << s << t << r << u << endl;
#define out5(s,t,r,u,o) cout << s << t << r << u << o << endl;
#define outd(s) cout << setprecision(15) << s << endl;
#define pb(s) push_back(s)

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }



int main()
{
	ll Q; cin >> Q;
	multiset<ll> s;
	multiset<ll> ans;
	s.insert(-1);
	s.insert(INF_LL);
	rep(_,Q) {
		ll t; cin >> t;
		if(t == 1) {
			ll x; cin >> x;
			auto lb = s.lower_bound(x);
			ll af = *(lb);
			ll bf = *(--lb);

			if(bf != -1) {
				ans.insert((bf^x));
			}

			if(af != INF_LL) {
				ans.insert((af^x));
			}
			if(bf != -1 && af != INF_LL) {
				ans.erase(ans.find(bf^af));
			}

			s.insert(x);

		} else if(t == 2) {
			ll x; cin >> x;
			auto lb = s.lower_bound(x);

			ll v  = *(lb);
			auto cp = lb;
			auto cp2 = lb;
			ll af = *(++lb); 
			ll bf = *(--cp);

			if(bf != -1) {
				ans.erase(ans.find(bf^v));
			}

			if(af != INF_LL) {
				ans.erase(ans.find(af^v));
			}

			if(bf != -1 && af != INF_LL) {
				ans.insert((bf^af));
			}

			s.erase(cp2);

		} else { // t = 3;
			out(*(ans.begin()));
		}
	} 
	return 0;
}