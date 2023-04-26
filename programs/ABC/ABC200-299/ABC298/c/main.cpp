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

multiset<ll> toB[MAX_N];
multiset<ll> toC[MAX_N];
int main()
{
	ll N, Q; cin >> N >> Q;
	rep(_, Q) {
		ll t; cin >>t;
		if(t == 1) {
			ll i, j; cin >> i >> j;
			if(toB[i].count(j) == false) {
				toB[i].insert(j);
			}
			
			toC[j].insert(i);

		} else if(t == 2) {
			ll i; cin >> i;
			for(auto c : toC[i]){
				out0(c) 
				out0(" ") 
			}
			cout << endl;

		} else {
			ll i; cin >> i;
			for(auto b : toB[i]){
				out0(b) 
				out0(" ") 
			}
			cout << endl;
		}

	}
	return 0;
}