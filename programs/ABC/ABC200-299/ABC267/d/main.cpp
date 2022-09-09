#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) max(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) min(a,MIN(b,c))

#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5


void solve() {

	ll N,M;cin>> N>>M;
	vector<ll>A(N);
	rep(i,N)cin>>A[i];
	ll dp[N+5][M+5];
	rep(i,N+5)rep(j,M+5)dp[i][j]=0;
	
	reps(j,1,M+1){
		reps(i,1,j+1){
			dp[i][j]=dp[i-1][j]+i*A[i-1];
		}
	
		reps(i,1+j,N+1){
		dp[i][j]=
		max(dp[i-1][j], dp[i-1][j-1]+j*A[i-1]);
		//cout << "dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<endl;
	    }
	}
	
	cout<<dp[N][M];
}


int main()
{
  solve();
	return 0;
}