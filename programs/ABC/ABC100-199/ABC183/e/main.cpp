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
#define MOD 1000000007

#define MAX_N (2*100000+5)


int main()
{
  ll h,w;cin>>h>>w;
  vector<string> S(h+2);
  
  reps(i,1,h+1){
  	cin>>S[i];
  	S[i]="#"+S[i]+"#";
  }
  S[0]=string("#",w+2);
  S[h+1]=string("#",w+2);
  
  
  vector dp= vector<vector<ll>>(h+2,vector<ll>(w+2,0));
  vector x= vector<vector<ll>>(h+2,vector<ll>(w+2,0));
  vector y= vector<vector<ll>>(h+2,vector<ll>(w+2,0));
  vector z= vector<vector<ll>>(h+2,vector<ll>(w+2,0));
  
  reps(i,1,h+1)reps(j,1,w+1)if(S[i][j]=='.'){
  	if(i==1&&j==1){
  		dp[i][j]=1;
  		continue;
  	}
  	x[i][j]=x[i-1][j]+dp[i-1][j];
  	y[i][j]=y[i][j-1]+dp[i][j-1];
  	z[i][j]=z[i-1][j-1]+dp[i-1][j-1];
  	dp[i][j]=x[i][j]+y[i][j]+z[i][j];
  	dp[i][j]%=MOD;
  	x[i][j]%=MOD;
  	y[i][j]%=MOD;
  	z[i][j]%=MOD;
  	
  }
  
  
  
  out(dp[h][w]);
  
  return 0;
}
