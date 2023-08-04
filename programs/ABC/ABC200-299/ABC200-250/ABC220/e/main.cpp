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

using mint = modint998244353;

// n = 4: 15 頂点, d = 2;


int main()
{
	ll n, D; cin >> n >> D;

	mint ans = 0;
	mint pow2[2*1000000+5];
	pow2[0] = 1;
	reps(i,1,2*1000000+5) pow2[i] = 2*pow2[i-1];


	rep(d,n) {

		if( D+d <= n-1 ) {
			ans += pow2[d] * pow2[D] * 2;
			ans += pow2[d] * pow2[D-1] * (D-1);
		} else {
			ll R = (n-1) - d;
			ll L = D-R;
			ll cnt = R-L+1;
			if(0 < cnt) {
				ans += pow2[d] * pow2[D-1] * cnt;
			} else {
				break;
			}
		}

	}
	out(ans.val())
	
	return 0;
}