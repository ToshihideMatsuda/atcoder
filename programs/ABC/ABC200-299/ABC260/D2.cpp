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
#define mkp(a,b) make_pair(a,b)

#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5
void solve() {
  ll N, K; cin >> N >> K;
 
  map<ll,set<ll> > P;
  ll ans[N+1];
  rep(i,N+1) ans[i] = -1; 
  P[INF_LL].insert(0);
 
  rep(i,N){ 
    ll p;
    cin >> p;
    auto idx = P.lower_bound(p);
    if((*idx).first == INF_LL ) {
      if( K == 1) {
        ans[p] = i+1;
      } else {
        P[p].insert(p);
      }
    } else {
      if( (*idx).second.size() == K -1) {
        ans[p] = i+1;
        for(auto j : (*idx).second) ans[j] = i+1;
        P.erase(idx);
      } else {
        P[p] = move((*idx).second);
        P[p].insert(p);
        P.erase(idx);
      }
    }
 
    
  }
 
  reps(i,1,N+1) cout << ans[i] << endl;
 
 
}
 

int main()
{
  solve();
	return 0;
}