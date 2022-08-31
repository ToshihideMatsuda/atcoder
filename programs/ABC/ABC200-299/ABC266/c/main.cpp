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
  	set<bool> v;
  	if(P[i+1][0]==P[i][0]){
  		rep(j,4)
  		if(i!=j&&(i+1)%4!=j) {
  			v.insert(P[j][0]<=P[i][0]);
  		}
  	}else if(P[i+1][1]==P[i][1]){
  		rep(j,4)
  		if(i!=j&&(i+1)%4!=j)
  		    v.insert(P[j][1]<=P[i][1]);
  	} else {
  		double dx =P[i+1][0]-P[i][0];
  		double dy =P[i+1][1]-P[i][1];
  	
  		double a = dy/dx;
  		double b = P[i][1] - a*P[i][0];
  		//y=a*x+b
  	
  		rep(j,4) if(i!=j&&(i+1)%4!=j) 
  		    v.insert(P[j][1]<=a*P[j][0]+b);
  	}
  	
  	if(v.size()>=2){
  		cout << "No";
  		return;
  	}	
  	
  }
  cout << "Yes";
}


int main()
{
  solve();
	return 0;
}