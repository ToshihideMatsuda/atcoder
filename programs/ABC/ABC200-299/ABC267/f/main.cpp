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
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


vector<ll> ans(MAX_N, -1);
unordered_map<ll,vector<ll>> tU;
vector<ll> K(MAX_N);
void dfs1(ll p, vector<ll> & v) {
  if(ck[p]) return;
  ck[p] = true;
  for(auto q : tU[p]) {
    if(K[q]  <= v.size()) {
      ans[q] = v[(v.size() - 1) - (K[q] - 1)];
    }
  }

  for(auto g: G[p]) if(ck[g] == false){
    v.push_back(p);
    dfs1(g,v);
    v.pop_back();
  }
}

void solve() {
  ll N; cin >> N;readG(N-1);

  ll Q; cin >> Q;
  rep(i,Q)  {
    ll u;
    cin >> u >> K[i];
    tU[u].push_back(i);
  }

  ll P[3]; 

  P[0] = 1;
  rep(i,2) {
    queue<pair<ll,ll>> Q;
    Q.push( {P[i], 0} );
    ll md = -1, p = -1;

    while(Q.size() > 0) {
      ll q, d;
      tie(q, d) = Q.front(); Q.pop();
      ck[q] = true;
      if(md < d) {
        md = d;
        p = q;
      }
      for(auto g : G[q]) if(ck[g] == false) {
        Q.push({g, d+1});
      }
    }
    P[i+1] = p;
    clear();
  }

  vector<ll> v;
  dfs1(P[1], v);
  clear();
  v.clear();
  dfs1(P[2], v);

  rep(i,Q) cout << ans[i] << endl;

}


int main()
{
  solve();
	return 0;
}