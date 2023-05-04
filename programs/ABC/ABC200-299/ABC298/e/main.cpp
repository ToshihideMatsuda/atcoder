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
#define MOD 998244353

#define MAX_N (2*1000+5)
vector<ll>G[MAX_N];


int main()
{
	ll N,M;cin>>N>>M;
	rep(i,M){
		ll u,v;cin>>u>>v;
		u--;v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	ll K;cin>>K;
	vector<ll>P;vector<ll>D;
	
	rep(_,K){
		ll p,d;cin>> p >> d;
		p--;
		P.push_back(p);
		D.push_back(d);
	}
	
	ll ans[N];rep(i,N)ans[i]=1;
	
	rep(i,K){
		
		if(D[i]==0)continue;
		
		vector<bool> ck(N);
		queue<pair<ll,ll>>Q;
		Q.push({P[i],0});
		ans[P[i]]=0;
		
		while(Q.size()>0){
			ll p0,d0;
			tie(p0,d0) =Q.front();Q.pop();
			ck[p0]=true;
			ans[p0]=0;
			
			if(d0<D[i]-1){
				for(auto g:G[p0])if(ck[g]==false){
					Q.push({g,d0+1});
				}
			}
		}
	}
	
	
	bool ok = true;
	rep(i,K){
		
		queue<pair<ll,ll>>Q;
		Q.push({P[i],0});
		vector<bool> ck(N);
		
		ll exist = false;
		while(Q.size()>0){
			ll p0,d0;
			tie(p0,d0) =Q.front();Q.pop();
			ck[p0]=true;
			
			if(d0==D[i]){
				if(ans[p0]==1){
					exist=true;
				}
			}else{
				for(auto g:G[p0])if(ck[g]==false)	Q.push({g,d0+1});
			}
		}
		
		if(exist== false){
			ok=false;
		}
	}
	
	if(ok){
		out("Yes")
		rep(i,N)cout<<ans[i];
		cout<<endl;
	}else{
		out("No")
	}
	
	
	return 0;
}
