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
	
	ll a=0;
	reps(i,1,n+1){
		ll p;
	cin>>p;
		if(p!=i)a++;
	}
	
	if(a==0||a==2)cout<<"YES";
	else cout<<"NO";
  
	return 0;
}
