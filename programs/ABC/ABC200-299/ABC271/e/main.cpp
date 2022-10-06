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
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N 2*100000+5
vector<tuple<ll,ll,ll>> G[MAX_N];
ll cost[MAX_N];
ll tekazu[MAX_N];

void solve() {
  ll N, M, K; cin >> N >> M >> K;
  rep(i,M) { 
    ll a, b, c; 
    cin >> a >> b >> c; 
    G[a].push_back({c,b,i+1});
  }

  vector<ll> E[M+5];
  rep(i,K) {
    ll e; cin >> e;
    E[e].push_back(i+1);
  }
  reps(e,1,M+1) {
    if(E[e].size() > 1) {
      sort(E[e].begin(),E[e].end());
    }
    E[e].push_back(INF_LL);
  }

  rep(i, MAX_N) cost[i] = INF_LL;
  rep(i, MAX_N) tekazu[i] = INF_LL;
  cost[1] = 0;
  tekazu[1] = 0;
  priority_queue<tuple<ll,ll, ll>, 
              vector<tuple<ll, ll, ll> >, 
              less<tuple<ll,ll, ll> > > Q;

  Q.push({0,1,0});

  while(Q.size() > 0) {
    ll c, p, i; 
    tie(c,p,i) = Q.top(); Q.pop();

    //if(c != cost[p]) continue;
      
    for(auto to : G[p]) {
      ll cc, q, e; 
      tie(cc, q, e) = to;
          
      auto idx = lower_bound(E[e].begin(),E[e].end(),i);
      if(*idx == INF_LL) continue;
      
      if(c + cc < cost[q] || *idx < tekazu[q]) {
        cost[q]   = min(cost[q], c + cc);
        tekazu[q] = min(tekazu[q], *idx); 
        if(q != N)
          Q.push({c + cc, q, *idx});
      }
    }
  }
  if(cost[N] == INF_LL )
    cout << -1 << endl;
  else
    cout << cost[N] << endl;
}


int main()
{
  solve();
	return 0;
}