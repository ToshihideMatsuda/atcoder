#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define max(a,b)   (a>b?a:b)
#define max3(a,b,c) max(a,max(b,c))
#define min(a,b)   (a<b?a:b)
#define min3(a,b,c) min(a,min(b,c))

#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5

set<ll> G[105];
ll N, M;
void solve() {
  cin >> N >> M;
  rep(_,M) {
    ll u, v; cin >> u >> v;
    G[u].insert(v);
    G[v].insert(u);
  }

  ll ans = 0;
  reps(a,1,N+1) {
    for(ll b : G[a]) if(a < b) 
      for(ll c : G[b]) if(b < c){
        if(G[a].count(c)) 
          ans ++;
      }
  }

  cout << ans << endl;
}


int main()
{
  solve();
	return 0;
}