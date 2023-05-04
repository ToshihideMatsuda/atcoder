#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
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

#define MAX_N (2*100000+5)


int main()
{
	ll N,T;cin>>N>>T;
	bool ok=false;
	ll C[N];rep(i,N){
		
		cin>>C[i];
		if(C[i]==T)ok=true;
	}
	ll R[N];rep(i,N){
		cin>>R[i];
		
	}
	if(ok==false)T=C[0];
	
	ll p=0,max=0;
	rep(i,N){
		if(T==C[i])
		if(max<R[i]){
			
			p=i;
			max=R[i];
		}
	}
	p++;
	cout<<p;
	
	return 0;
}
