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
#define INF_LL (1LL << 59)
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N (2*100000+5)

bool reachable[2005][2005];
bool exist[2005][2005];
int main()
{
	ll n,m;cin>> n>> m;
	vector<vector<ll>>G(n+5);
	rep(i,m){
		ll u,v; cin>> u>>v;
		G[u].push_back(v);
		exist[u][v]=true;
	}
	
	reps(i,1,n+1){
		queue<ll> Q;
		vector<bool> ck(n+5);
		Q.push(i);
		ck[i]=true;
		while(Q.size()>0){
			auto q=Q.front();Q.pop();
			if(i!=q){
				reachable[i][q]=true;
				//out2(i)out2("->")out(q)
			}
			for(auto g:G[q])if(ck[g]==false){
				ck[g]=true;
				Q.push(g);
			}
		}
	}
	
	ll ans =0;
	reps(i,1,n+1)reps(j,1,n+1){
		if(i!=j) if(!exist[i][j] && reachable[i][j]) ans++;
	}
	out(ans)
	
	
	
	return 0;
}
