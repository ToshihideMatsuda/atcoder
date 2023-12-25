#include <bits/stdc++.h> 
#include <atcoder/all>
using namespace std;
using namespace atcoder;

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
#define out0(s) cout << s;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N (2*100000+5)

using mint = modint998244353;

int main()
{
	ll n;cin>>n;
	vector dp= vector<vector<mint>>(n+1,vector<mint>(n+1,0));
	
	dp[1][1]=1;
	
	vector<mint> pow2(n+1);
	pow2[0]=1;
	reps(i,1,n+1)pow2[i]=2*pow2[i-1];
	
	reps(i,2,n+1){
		mint tmp =0;
		ll k=1;
		for(int j=i-1;j>0;j--){
			tmp+=dp[i-1][j]/pow2[k++];
		}
		
		tmp *= pow2[k]/(pow2[k]-1);
		
		dp[i][i]=tmp;
		dp[i][1]=dp[i][i]/2;
		
		reps(j,2,i){
			dp[i][j]=(dp[i][j-1]+dp[i-1][j-1])/2;
		}
	}
	
	reps(i,1,n+1){
		out0(dp[n][i].val())
		out0(" ")
	}
	
	return 0;
}
