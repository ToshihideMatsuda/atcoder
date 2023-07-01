#include <bits/stdc++.h> 
using namespace std;

typedef int ll;
typedef unsigned long long ull;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) MIN(a,MIN(b,c))
#define out0(s) cout << s;
#define out(s) out1(s)
#define out1(s) cout << s << endl;
#define out2(s,t) cout << s << t << endl;
#define out3(s,t,r) cout << s << t << r << endl;
#define out4(s,t,r,u) cout << s << t << r << u << endl;
#define out5(s,t,r,u,o) cout << s << t << r << u << o << endl;
#define outd(s) cout << setprecision(15) << s << endl;
#define pb(s) push_back(s)

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD


#define MAX_N (3*100000+5)

vector<pair<ll,ll>> ck(MAX_N,{-1,0});
vector<ll> cnt(MAX_N);
set<pair<ll,ll>>G[MAX_N];

int main()
{
	ll N,M;
	cin>>N >>M;
	
	rep(i,M){
		ll u,v,w;
		cin>> u >> v>>w;
		G[u].insert({w,v});
		G[v].insert({w,u});
	}

	rep(i,N+1) {
		cnt[i] = G[i].size();
	}
	
	ll 	K;cin>>K;
	vector<ll>A;
	rep(i,K){
		ll a;
		cin>>a;
		ck[a]={0,0};
		A.push_back(a);
	}

	ll D;cin>>D;
	vector<ll>X(D+1);
	reps(d,1,D+1)cin>>X[d];
	X.push_back(-1);
	

	priority_queue<
		pair<ll,ll>, 
		vector<pair<ll, ll>>, 
		less<pair<ll,ll> > > Q;
	vector<ll> nx = {};

	for(auto a: A) {
		Q.push({X[1],a});
	} 
	reps(d,1,1+D){

		nx = {};

		unordered_map<ll,ll> y;
		while(Q.size() > 0) {
			bool add=false;

			ll x,a;
			tie(x,a) = Q.top();Q.pop();
			if(x == ck[a].second && ck[a].first == d && y[a] > 1) continue;
			if(x < ck[a].second && ck[a].first == d) continue;

			for(auto g : G[a]){
				ll p = g.second;
				ll x2 = x-g.first;
				
				if(x2 < 0) {
					break;
				}

				if(ck[p].first  == -1) {
					if( 0 <= x2){
						cnt[p]--;
						ck[p]={d, x2};
						y[p]++;
						Q.push({x2, p});
					} 
				} 

				if( ck[p].first ==  d &&  ck[p].second < x2){
					ck[p]={d, x2};
					Q.push({x2, p});
				} 
			}

			if(cnt[a] > 0) {
				nx.push_back(a);
			}
		}
		for(auto a:nx)  Q.push({X[d+1],a});
	}
	
	reps(i,1,1+N)out(ck[i].first)
	
	
	return 0;
}
