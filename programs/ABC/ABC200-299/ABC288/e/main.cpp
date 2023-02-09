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
#define out(s) cout << s << endl;
#define out2(s) cout << s;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N 1000000+5
ll cost[5005][5005];//
ll dp[5005][5005];
//dp[m][n]:m-index res n
void solve(){
	
	ll N,M;cin>>N>>M;
	vector<ll>A(N+1),C(N+1);
	set<ll>X;
	rep(i,N)cin>>A[i+1];
	rep(i,N)cin>>C[i+1];
	rep(i,M){
		ll x;
		cin>>x;
		X.insert(x);
	}
	
	reps(i,1,N+1){
		cost[i][1]=C[i];
		reps(j,2,N+1){
			cost[i][j]= min(cost[i][j-1],C[i-(j-1)]);
		}
		//reps(j,1,N+1)cout<<i<<","<<j<<"="<<cost[i][j]<<endl;
	}
  
  ll cnt = 0;
	reps(i,1,N+1){
    dp[i][cnt] = dp[i-1][cnt];
		reps(j,cnt+1,i+1){
			dp[i][j]=dp[i-1][j-1]+A[i]+cost[i][j];
			if(X.count(i)){
			}
			else if(j <= i-1){
			  dp[i][j]=min(dp[i][j],dp[i-1][j]);
			}
			
			//cout<<"dp["<<i<<"]["<<j<<"]="<<dp[i][j]<<endl;
		}

			if(X.count(i)){
        cnt++;
			}
		
	}
	
	ll ans =INF_LL;
	reps(i,X.size(),N+1){
		//cout<<dp[N][i]<<endl;
		ans=min(ans,dp[N][i]);
	}
	cout<< ans;
}

int main(){
    solve();
    return 0;
}

