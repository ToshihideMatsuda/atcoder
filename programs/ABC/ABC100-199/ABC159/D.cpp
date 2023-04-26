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
ll A[MAX_N];
ll C[MAX_N];
int main()
{
  ll N; cin>> N;
  
  rep(i,N){
  	cin>> A[i];
  	C[A[i]]++;
  }
  
  ll all=0;
  rep(i,MAX_N)if(C[i]>1)all+=C[i]*(C[i]-1)/2;
  
  rep(i,N){
  	if(C[A[i]]>1)
  	{
  		ll ans = all 
  		- C[A[i]]*(C[A[i]]-1)/2
  		+ (C[A[i]]-1)*(C[A[i]]-2)/2;
  		cout<< ans<<endl;
  	}else{
  		cout<<all<<endl;
  	}
  }
  
  return 0;
}
