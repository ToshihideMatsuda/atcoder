#include <bits/stdc++.h> 
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

#define MAX_N (2*100000+5)
vector<pair<ll,ll>> G[MAX_N];
vector<pair<ll,ll>> H[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readGH(ll M) { 
	rep(i,M) { 
		ll a, b, c; cin >> a >> b >> c; 
		G[a].push_back({c, b}); H[b].push_back({c, a});
	} 
}

ll cost[MAX_N];
void dijkstra(ll start){
  priority_queue<pair<ll,ll>, vector<pair<ll, ll>>, greater<pair<ll,ll> > > Q;

  Q.push(make_pair(0,start));

  rep(i, MAX_N) cost[i] = INF_LL;
  cost[start] = 0;

  while(Q.size() > 0) {
      auto from = Q.top();Q.pop();
      ll p = from.second;
      ll fromC = from.first;

      if(fromC != cost[p]) continue;
      
      for(auto to : G[p]) {
          ll q = to.second, toC = to.first;

          if(fromC + toC < cost[q]) {
              cost[q] = fromC + toC;
              Q.push(make_pair(cost[q] ,q));
          }
      }
  }
}



int main()
{
	ll N, M; cin >> N >> M;
	readGH(M);
	reps(i,1,N+1) {
		dijkstra(i);
		ll c = INF_LL;
		for(auto h : H[i] ){
			c = MIN(c, cost[h.second] + h.first);
		}
		if(c == INF_LL) {
			c = -1;
		}
		out(c)
	}

	return 0;
}