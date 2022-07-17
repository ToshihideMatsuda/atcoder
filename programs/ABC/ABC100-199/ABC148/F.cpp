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
#define mp(a,b) make_pair(a,b)

#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 100000+5
vector<ll> G[MAX_N];
ll ud[MAX_N], vd[MAX_N];


void solve() {
  ll N, u ,v; cin >> N >> u >> v;
  rep(i,N-1) {
    ll a, b; cin >> a >> b;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  rep(i,MAX_N) {
    ud[i] = -1;
    vd[i] = -1;
  }
  queue<ll> Q;
  ud[u] = 0;
  Q.push(u);
  while(Q.size() >0) {
    auto q = Q.front();Q.pop();
    for(auto g : G[q])if(ud[g] == -1) {
      Q.push(g);
      ud[g] = ud[q] + 1;
    }
  }


  vd[v] = 0;
  Q.push(v);
  while(Q.size() >0) {
    auto q = Q.front();Q.pop();
    for(auto g : G[q])if(vd[g] == -1) {
      Q.push(g);
      vd[g] = vd[q] + 1;
    }
  }

  ll ans = 0;

  rep(i,N+1) {
    if(ud[i] < vd[i]) {
      ans = max(vd[i] - 1, ans);
    }
  }

  cout << ans << endl;

}


int main()
{
  solve();
	return 0;
}