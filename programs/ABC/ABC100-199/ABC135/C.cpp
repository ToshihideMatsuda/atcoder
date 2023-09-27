#include <iostream> 
#include <vector> 
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define max(a,b)   (a>b?a:b)
#define max3(a,b,c) max(a,max(b,c))
#define min(a,b)   (a<b?a:b)
#define min3(a,b,c) min(a,min(b,c))


#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5



int main()
{
	
	ll n;cin>>n;
	vector<ll>a(n+1),b(n);
	rep(i,n+1)cin>>a[i];
	rep(i,n)cin>>b[i];
	ll ans=0;
	for(int i=n-1;i>=0;i--){
		ll c =min(a[i+1],b[i]);
		ans+=c;
		b[i]-=c;
		a[i+1]-=c;
		ll d=min(a[i],b[i]);
		ans+=d;
		b[i]-=d;
		a[i]-=d;
	}
  cout<<ans;
	return 0;
}
