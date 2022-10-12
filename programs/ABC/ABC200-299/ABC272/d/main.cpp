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

int main()
{
	ll N,M;cin>>N>>M;
	ll G[N+5][N+5];
	reps(i,1,N+1)reps(j,1,N+1)G[i][j]=-1;
	vector<pair<ll,ll>> d;
	rep(i,N)rep(j,N)if(i*i+j*j==M){
		d.push_back({i,j});
		d.push_back({-i,j});
		d.push_back({i,-j});
		d.push_back({-i,-j});
	}
	
	queue<tuple<ll,ll,ll>>Q;
	Q.push({1,1,0});
	G[1][1]=0;
	while(Q.size()>0){
		ll x,y,p=0;
		tie(x,y,p)= Q.front();Q.pop();
		for(auto v:d){
			ll dx,dy=0;
			tie(dx,dy)=v;
			
			if(0<=x+dx && x+dx<=N &&
			   0<=y+dy && y+dy<=N)
			if(G[x+dx][y+dy]==-1){
				G[x+dx][y+dy]=p+1;
				Q.push({x+dx,y+dy,p+1});
			}
		}
	}
	
	
	reps(i,1,N+1){
		reps(j,1,N+1)cout << G[i][j] << " ";
		cout << endl;
	}
	
	
	return 0;
}
