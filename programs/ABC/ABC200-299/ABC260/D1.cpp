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
 
  vector<pair<ll,set<ll> > > PP;
  ll ans[N+1];
  rep(i,N+1) ans[i] = -1; 

  PP.push_back(mkp(INF_LL,set<ll>()));
 
  rep(i,N){ 
    ll p;
    cin >> p;
    auto idx = std::lower_bound( PP.begin(), PP.end(), mkp(p,set<ll>()));
    ll ii = (*idx).first;
    if(ii == INF_LL ) {
      if(K==1) {
        ans[p] = i+1;
      }
      else {
        PP[PP.size()-1] = mkp(p, set<ll>());
        PP[PP.size()-1].second.insert(p);
        PP.push_back(mkp(INF_LL,set<ll>()));
      }
    } else {
      if( (*idx).second.size() == K -1) {
        ans[p] = i+1;
        for(auto j : (*idx).second) ans[j] = i+1;
        PP.erase(idx);
      } else {
        (*idx).second.insert(p);
        (*idx).first = p;
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