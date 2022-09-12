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
  	
  	double dx1 =P[i+2][0]-P[i][0];
  	double dy1 =P[i+2][1]-P[i][1];
  	double b1  =dx1*P[i][1]-dy1*P[i][0];
  	//dx1*y=dy1*x+b1
  	
  	double dx2 =P[i+3][0]-P[i+1][0];
  	double dy2 =P[i+3][1]-P[i+1][1];
  	double b2  =dx2*P[i+1][1]-dy2*P[1+i][0];
  	//dx2*y=dy2*x+b2
  	
  	if(dx2*dy1-dx1*dy2==0){
  		cout<<"No";
  	return;
  	}
  	
  	double x0 = -(dx2*b1-dx1*b2)/(dx2*dy1-dx1*dy2);
  	double y0 = (dy2*b1-dy1*b2)/(dy2*dx1-dy1*dx2);
  	
  	if(min(P[i][0],P[i+2][0])<= x0 && 
  	   x0 <=max(P[i][0],P[i+2][0]) &&
  	   min(P[i][1],P[i+2][1])<= y0 && 
  	   y0 <=max(P[i][1],P[i+2][1]) ){
  		continue;
  	}
  	
  	//cout << x0<<","<<y0<<endl;
  	cout<<"No";
  	return;
  	
  }
  cout << "Yes";
}


int main()
{
  solve();
	return 0;
}