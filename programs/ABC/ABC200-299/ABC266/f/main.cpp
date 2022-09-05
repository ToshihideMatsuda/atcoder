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

#define MAX_N 2*100000+5

ll kind[MAX_N];

vector<ll> G[MAX_N];
bool ch[MAX_N];
bool ex = false;
vector<ll> getCycle(ll p, vector<ll>& pre){
  vector<ll> empty;
  if(ex) return empty;

  ch[p] = true;
  for(auto g : G[p]) if(g != pre.back()){
    if(ch[g]) {
      bool start = false;
      vector<ll> cycle;
      for(auto pp : pre) { 
        if(pp == g)
          start = true;

        if(start) {
          cycle.push_back(pp);
        }
      }
      cycle.push_back(p);
      ex = true;
      return cycle;
    }

    pre.push_back(p);
    vector<ll> ret = getCycle(g, pre);
    pre.pop_back();

    if(ret.size() > 0) {
      return ret;
    }
  }
  return empty;
}

set<ll> s;

void dfs2(ll p, ll k){
  if(ch[p]) return;

  ch[p] = true;
  kind[p] = k;
  for(auto g : G[p]) if(ch[g] == false && !s.count(g)) {
    dfs2(g,k);
  }
}

void solve() {
  ll N; cin >> N;
  rep(i,N) {
    ll u, v; cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }

  vector<ll> pre{0};
  vector<ll> cycle = getCycle(1,pre);
  
  for(auto e: cycle) s.insert(e);
  rep(i,MAX_N) ch[i] = false;

  for(auto e: cycle) dfs2(e,e);

  ll Q; cin >> Q;
  rep(i,Q) {
    ll x, y; cin >> x >> y;
    if(kind[x] == kind[y]) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}


int main()
{
  solve();
	return 0;
}