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
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


ll N, X, Y; 
bool dfs(ll p, vector<ll>& v) {
  ck[p] = true;
  if(p == Y) {
    for(auto vv : v) {
      cout << vv << " ";
    }
    cout << endl;
    return true;

  }
  for(auto g : G[p]) if(ck[g] == false){
    v.push_back(g);
    bool ret = dfs(g,v);
    if(ret) return true;
    v.pop_back();
  }
  return false;
}

void solve() {cin >> N >>  X >> Y;
  readG(N-1);
  vector<ll> v = {X};

  dfs(X, v);
}


int main()
{
  solve();
	return 0;
}