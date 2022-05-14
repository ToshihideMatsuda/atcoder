#include <bits/stdc++.h> 
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

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}

vector<ll> G[MAX_N];
bool ch[MAX_N];
vector<pair<ll,ll>>T[3];

void dfs(ll u) {
  ch[u] = true;
  for(auto v : G[u]) {
    if(!ch[v]) {
      T[1].push_back({u,v});
      dfs(v);
    }
  }
}

void solve() {
  ll N, M;
  cin >> N >> M;

  rep(i,M) {
    ll u, v;
    cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u); 
  }

  rep(i,N+1) ch[i] = false;

  //dfs
  dfs(1);

  rep(i,N+1) ch[i] = false;

  queue<ll> Q;

  Q.push(1);
  ch[1] = true;

  while(Q.size() > 0) {
    ll u = Q.front(); Q.pop();
    for(auto v : G[u]) {
      if(!ch[v]) {
        T[2].push_back({u,v});
        ch[v] = true;
        Q.push(v);
      }
    }
  }
  reps(i,1,3) {
    for( auto e : T[i]) {
      cout << e.first << " " << e.second << endl;
    }
  }


}


int main()
{
  solve();
	return 0;
}