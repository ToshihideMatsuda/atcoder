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
  double P[8][2];
  rep(i,4)rep(j,2){
  	cin>>P[i][j];
  	P[i+4][j]=P[i][j];
  }
  
  rep(i,4){
  	
  	double a1 =P[i+2][0]-P[i+1][0];
  	double b1 =P[i+2][1]-P[i+1][1];
  	
  	double a2 =P[i][0]-P[i+1][0];
  	double b2 =P[i][1]-P[i+1][1];
  	
  	if(a1*b2-a2*b1 <= 0){
  		cout << "No";return;
  	}
  	
  }
  cout << "Yes";
}


int main()
{
  solve();
	return 0;
}