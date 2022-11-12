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

#define MAX_N 2*100000+5
unordered_map<ll,vector<ll>> G;

set<ll> ck;

void solve() {
  ll N; cin >> N;
  rep(i,N){
    ll a, b; 
    cin >> a >> b; 
    G[a].push_back(b); 
    G[b].push_back(a);
  }
  queue<ll> Q;
  Q.push(1);
  while(Q.size() > 0) {
    auto q = Q.front(); Q.pop();
    ck.insert(q);
    for(auto g: G[q]){
      if(ck.count(g))continue;
      ck.insert(g);
      Q.push(g);
    }
  }

  ll ans = 1;
  for(auto q : ck) ans = MAX(ans,q);
  cout << ans << endl;


}


int main()
{
  solve();
	return 0;
}