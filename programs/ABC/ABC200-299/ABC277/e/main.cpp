#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) max(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) min(a,MIN(b,c))

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N 2*100000+5
vector<pair<ll,ll>> G[MAX_N];
ll cost[MAX_N][2];
bool S[MAX_N];


void solve() {
  ll N, M, K; cin >> N >> M >> K;
  rep(i,M) {
    ll u, v, a;
    cin >> u >> v >> a;
    G[u].push_back({v,a});
    G[v].push_back({u,a});
  }
  rep(i,K) {
    ll s;
    cin >> s;
    S[s] = true;
  }
  rep(i,MAX_N) {
    cost[i][0] = INF_LL;
    cost[i][1] = INF_LL;
  }
  ll t[2] = {1,0}; 
  queue<pair<ll,ll>> Q;
  Q.push({1,1}); 
  cost[1][1] = 0;
  while(Q.size() > 0) {
    ll q, a;
    tie(q,a) = Q.front(); Q.pop();
    if(S[q]) {
      if(cost[q][a] < cost[q][t[a]]) {
        cost[q][t[a]] = cost[q][a];
        Q.push({q,t[a]});
      }
    }
    for(auto g : G[q]) {
      if(g.second == a) {
        if( cost[q][a] + 1 < cost[g.first][a]){
          cost[g.first][a] = cost[q][a] + 1;
          Q.push({g.first,a});
        }
      }
    }
  }

  ll ans = MIN(cost[N][0], cost[N][1]);
  if(ans == INF_LL) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }


}


int main()
{
  solve();
	return 0;
}