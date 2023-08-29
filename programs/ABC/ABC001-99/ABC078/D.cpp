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
#define out(s) cout << s << endl;
#define out2(s) cout << s;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD (1000000000+7)

#define MAX_N (100000+5)

int main()
{
	ll n,z,w;cin>>n>>z>>w;
	
	vector<ll>a(n+1);rep(i,n)cin>>a[1+i];
	
	a[0]=w;
	ll dp[2][n+1];
	//dp[0][m]=MAX(dp[1][m+1],..,dp[1][n],abs(a[m-1]-a[n]));
	//dp[1][m]=MIN(dp[0][m+1],..,dp[0][n],abs(a[m-1]-a]n]));
	dp[0][n]=abs(a[n-1]-a[n]);
	dp[1][n]=abs(a[n-1]-a[n]);
	
	for(int m=n-1;m>0;m--){
		ll tmp0=abs(a[m-1]-a[n]);
		ll tmp1=tmp0;
		reps(i,m+1,n+1){
			tmp0=MAX(tmp0,dp[1][i]);
			tmp1=MIN(tmp1,dp[0][i]);
		}
		dp[0][m]=tmp0;
		dp[1][m]=tmp1;
		
		
	}
	out(dp[0][1]);

	
	return 0;
}
