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

using mint = modint998244353;

int main()
{


	ll t; cin >> t;
	rep(_,t) {
		ll n; cin >> n;
		ll base =  (1 << 2) + (1 << 1) + 1;
		if(n < base) {
			out(-1)
			continue;
		}

		ll l0 = 2;

		while(base <= n) {
			ll a = base << 1;
			if (a < 0) break;
			if (n < a) break;
			base = a;
			l0++;
		}

		//  1110....000で最大の数がbase
		
		// 10000....011を検証
		l0++;
		if((1L << l0) + (1L << 1) + 1L  <= n) {
			ll l1 = 1;
			reps(k,1,l0) {
				if((1L << l0) + (1L << k) + 1L  <= n ) l1 = k;
			}

			ll l2 = 0;
			reps(k,0,l1) {
				if((1L << l0) + (1L << l1) + (1L << k)  <= n ) l2 = k;
			}

			ll ans = (1L << l0) + (1L << l1) + (1L << l2);
			out(ans)

		} else {
			out(base)
		}
	}
	return 0;
}