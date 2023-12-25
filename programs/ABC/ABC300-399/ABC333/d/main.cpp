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
	ll n;cin>>n;
	vector<ll>G[n+1];
	rep(i,n-1){
		ll u,v;cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	if(G[1].size()==1){
		out(1);
		return 0;
	}
	vector<ll> target;
	vector<ll> checked(n+1);
	checked[1]=true;
	for(auto g:G[1]){
		queue<ll> Q;
		Q.push(g);
		checked[g]=true;
		ll tmp=1;
		while(Q.size()>0){
			auto q=Q.front();Q.pop();
			for(auto p:G[q])if(checked[p]==false){
				checked[p]=true;
				Q.push(p);
				tmp++;
			}
		}
		target.push_back(tmp);
	}
	sort(target.begin(),target.end());
	ll ans=1;
	rep(i,target.size()-1)ans+=target[i];
	out(ans);
	
	return 0;
}
