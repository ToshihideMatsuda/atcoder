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

ll A[MAX_N][7];
ll dp[MAX_N][7];
bool ex[MAX_N][7];

void solve() {
  ll N; cin >> N;
  ll T=0;
  rep(i,N){
  	ll t,x,a;cin>>t>>x>>a;
  	T=MAX(T,t);
  	A[t][x+1]=a;
  }
  ex[0][1]=true;
  
  reps(t,1,T+1){
  	reps(x,1,6){
  		ll a = 0;
  		if(ex[t-1][x]){
  			ex[t][x]=true;
  			a = MAX(a,dp[t-1][x]+A[t][x]);
  		}
  		if(ex[t-1][x-1]){
  			ex[t][x]=true;
  			a = MAX(a,dp[t-1][x-1]+A[t][x]);
  		} 
  		if(ex[t-1][x+1]){
  			ex[t][x]=true;
  			a = MAX(a,dp[t-1][x+1]+A[t][x]);
  		} 
  		
  		dp[t][x]=a;
  	}
  }
  
  
  
  ll ans=0;
  reps(x,1,6) ans=MAX(ans,dp[T][x]);
  cout << ans<< endl;
  
}
 

int main()
{
  solve();
	return 0;
}