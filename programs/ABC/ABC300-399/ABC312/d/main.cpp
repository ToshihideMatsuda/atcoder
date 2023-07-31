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
#define pb(s) push(s)

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N (2*100000+5)


int main()
{
	string s; cin >> s;
	vector dp = vector(s.size() + 1, vector(s.size() + 1,0));
	dp[0][0] = 1;
	rep(i,s.size()) {
		if(s[i] == '(') {
			rep(j,s.size()) dp[i+1][j+1] = dp[i][j]; 
		} else if(s[i] == ')') {
			rep(j,s.size()) dp[i+1][j] = dp[i][j+1]; 
		} else {
			rep(j,s.size()) dp[i+1][j+1] += dp[i][j]; 
			rep(j,s.size()) {
				dp[i+1][j] += dp[i][j+1];
				dp[i+1][j] %= MOD;
			}
		}
	} 

	out(dp[s.size()][0])

	return 0;
}