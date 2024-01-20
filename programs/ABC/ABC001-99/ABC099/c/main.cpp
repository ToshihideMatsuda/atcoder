#include "bits/stdc++.h"
#include <iostream>
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
#define out0(s) cout << s;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N (2*100000+5)

int main()
{
	ll N;cin>>N;
	vector<ll> dp(N+1);
	rep(i,N+1)dp[i]=INF_LL;
	dp[0]=0;
	rep(i,N)if(dp[i]<INF_LL){
		ll c=0;
		for(ll j=9;j<=N;j*=9)if(i+j<N+1){
			c++;
			dp[i+j]=MIN(dp[i+j],dp[i]+1);
		}
		
		c=0;
		for(ll j=6;j<=N;j*=6)if(i+j<N+1){
			dp[i+j]=MIN(dp[i+j],dp[i]+1);
		}
	}
	
	//rep(i,N+1){out0(i)out0(":")out(dp[i])}
	
	ll ans=INF_LL;
	for(ll i=N;i>-1;i--)ans=MIN(dp[i]+N-i,ans);
	out(ans);
	
	return 0;
}
