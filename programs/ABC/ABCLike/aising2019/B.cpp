#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) MIN(a,MIN(b,c))

int main()
{
  ll N,A,B;cin>>N>>A>>B;
  ll a=0,b=0,c=0;
  rep(i,N){
  	ll P;cin>>P;
  	if(P<=A){
  		a++;
  	}else if(P<=B){
  		b++;
  	}else c++;
  }
  cout<<MIN3(a,b,c);
  return 0;
}