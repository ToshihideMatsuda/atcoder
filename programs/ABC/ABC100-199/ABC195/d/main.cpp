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

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


void solve() {
  ll N, M, Q; cin >> N >> M >> Q;
  vector<ll> W(N), V(N), X(M);
  rep(i,N) cin >> W[i] >> V[i];
  rep(i,M) cin >> X[i];

  vector<vector<pair<ll,ll>>> canX;

  rep(i,M) {
    vector<pair<ll,ll>> can;
    rep(j,N) {
      if(W[j] <= X[i]){ // 格納可能
        can.push_back({V[j],j}); 
      }
    }
    sort(can.begin(),can.end(),greater<pair<ll,ll>>());
    canX.push_back(can);
  }

  rep(_, Q) {
    ll L, R; cin >> L >> R;
    L--; R--;
    set<ll> used;
    ll ans = 0;

    //ソートしておかないと、小さい箱でも入れられるものを大きな箱に入れてしまう
    vector<pair<ll,ll>> Xi;
    rep(i,M) if(i < L || R < i) {
      Xi.push_back({X[i],i});
    }
    sort(Xi.begin(),Xi.end());

    for(auto Xii : Xi) {
      ll i = Xii.second;
      for(auto can : canX[i]) {
        if(!used.count(can.second)) {
          used.insert(can.second);
          ans += can.first;
          break;
        }
      }
    }

    cout << ans << endl;

  }
  




}


int main()
{
  solve();
	return 0;
}