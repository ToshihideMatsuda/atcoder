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
	ll n,m;cin>>n>>m;
	vector<tuple<ll,ll,ll>> G[n+1];
	rep(i,m){
		ll u,v,b,c;cin>>u>>v>>b>>c;
		G[u].push_back({v,b,c});
	}
	
	double lb = 0.0,ub=INF_LL;
	while(ub-lb>0.000000001){
		double X=(lb+ub)/2;
		
		vector<double> cost(n+1,-1e300);
		
		cost[1]=0;
		
		reps(p,1,n){
			double w =cost[p];
			for(auto [q,b,c] :G[p]){
				double w1 = b-X*c;
				if(cost[q] < w+w1){
					cost[q]=w+w1;
					if(cost[n]>=0){
						lb =X;
						goto next;
					}
				}
			}
		}
		if(cost[n]>=0){
			lb =X;
		}else {
			ub =X;
		}
		next:
		continue;
	}
	
	cout<<setprecision(15)<<(lb);
	
	return 0;
}
