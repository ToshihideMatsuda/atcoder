#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <stack>
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
#define out0(s) cout << s;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N (2*100000+5)



int main()
{
	ll N;cin>>N;
	ll nn=N;
	auto D=vector<vector<ll>>(N,vector<ll>(N,0));
	vector<pair<string,ll>> Q;
	while(N>=3){
		Q.push_back({"R",N-1});
		Q.push_back({"D",N-1});
		Q.push_back({"L",N-1});
		N--;
		Q.push_back({"U",N-1});
		if(N<3)break;
		Q.push_back({"R",1});
		N--;
	}
	
	ll x=0,y=0;
	D[0][0]=1;
	ll t=1;
	for(auto [c,n]:Q){
		rep(i,n){
			
		if(c=="R")y++;
		else if(c=="D")x++;
		else if(c=="L")y--;
		else x--;
		//cout<<"x="<<x<<",y="<<y<<endl;
		D[x][y]=++t;
		}
	}
	
	rep(x,nn){
		rep(y,nn){
			if(D[x][y]==0)out0("T")
			else out0(D[x][y])
			out0(" ")
		}
		cout<<endl;
	}

	return 0;
}
