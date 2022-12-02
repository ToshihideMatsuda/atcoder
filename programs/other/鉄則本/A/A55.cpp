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

#define MAX_N 300000 + 5

void solve() {
  set<ll> s;
  ll Q; cin >> Q;
  rep(i,Q) {
    ll t, x; cin >> t >> x;
    if(t == 1) {
      s.insert(x);
    } else if(t==2) {
      s.erase(x);
    } else {
      auto it =s.lower_bound(x);
      if(it == s.end()) cout << -1 << endl;
      else cout << *(it) << endl;
    }
  }

}

int main()
{
  solve();
	return 0;
}