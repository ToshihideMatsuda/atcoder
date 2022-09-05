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
  ll N; cin >> N;
  double ans =0;
  
  rep(i,N){
  	double s=0;
  	reps(j,1,7)if(ans<j)s+=(j);else s+=ans;
  	ans=s/6.0;  	
  }
  
  cout << setprecision(15)<<ans<< endl;
}


int main()
{
  solve();
	return 0;
}