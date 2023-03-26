#include <bits/stdc++.h> 
#include <unordered_map>
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

#define MAX_N (5*100000+5)

ll R[MAX_N][10];
unordered_map<ll,ll> A;

int main()
{
	string S; cin >> S;
	rep(i,S.size()) {
		rep(j,10)R[i+1][j] = R[i][j];
		R[i+1][S[i] - '0'] ++;
	}
	rep(i,S.size()+1) {
		ll two = 1;
		ll a = 0;
		rep(j,10) {
			a += (R[i][j] % 2) * two;
			two *= 2;  
		}
		A[a]++;
	}

	ll ans = 0;
	for(auto idx = A.begin(); idx != A.end(); ++idx) {
		ll a = (*idx).second ;
		if(a > 1) {
			ans += a*(a-1)/2;
		}
	}
	out(ans)

	return 0;
}