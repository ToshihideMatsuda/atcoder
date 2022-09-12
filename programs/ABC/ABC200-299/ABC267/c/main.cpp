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
	ll sum =0;
	ll sum2=0;
	rep(i,M){
		sum+=A[i];
		sum2+=A[i]*(i+1);
	}
	
	ll ans =sum2;
	reps(i,M,N){
		sum2 += -sum + M*A[i];
		sum += A[i]-A[i-M];
		ans =max(ans,sum2);
	}
	cout<<ans;
}


int main()
{
  solve();
	return 0;
}
