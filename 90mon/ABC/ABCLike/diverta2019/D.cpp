#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define max(a,b)   (a>b?a:b)
#define max3(a,b,c) max(a,max(b,c))
#define min(a,b)   (a<b?a:b)
#define min3(a,b,c) min(a,min(b,c))

int main() {
	ll n;cin>>n;
	//N=qm+q;
	//N=q(m+1);
	ll ans =0;
	for(ll i = 1; i*i <=n;i++)
	if(n%i==0){
		ll m = n/i;
		if(i-1>0 && n/(i-1)==n%(i-1)){
			ans+=i-1;
		}
		if(m-1>0&& n/(m-1)==n%(m-1)){
		ans+=m-1;
		}
		
	}
	cout << ans;
}

