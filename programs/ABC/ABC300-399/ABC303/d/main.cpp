#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
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

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N*2];


int main()
{
	ll X,Y,Z;cin>>X>>Y>>Z;
	string S;cin>>S;
	ll L=S.size();
	ll dp[L+1][2];
	rep(i,L+1)rep(j,2)dp[i][j]=INF_LL;
	dp[0][0]=0;
	dp[0][1]=Z;
	
	rep(i,L)
	{
		if(S[i]=='a'){
			dp[i+1][0]=MIN3(dp[i][0]+X,
			                dp[i][1]+Z+X,
			                dp[i][1]+Z+Y);
			
			dp[i+1][1]=MIN3(dp[i][1]+Y, 
			               dp[i][0]+Z+X,
			               dp[i][0]+Z+Y);
			
		}else{
			dp[i+1][0]=MIN3(dp[i][0]+Y,
			                dp[i][1]+Z+X,
			dp[i][1]+Z+Y);
			
			dp[i+1][1]=MIN3(dp[i][1]+X, 
			               dp[i][0]+Z+X,
			dp[i][0]+Z+Y);
			
		}
		//ut3(dp[i+1][0],",",dp[i+1][1])
	}
	

	ll ans =MIN(dp[L][0],dp[L][1]);
	out(ans)
	
	
	return 0;
}
