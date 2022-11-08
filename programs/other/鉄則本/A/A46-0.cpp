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
  ll N; cin >> N;
  vector<ll> X(N+1),Y(N+1);
  rep(i,N) cin >> X[i+1] >> Y[i+1];
  set<ll> s;
  reps(i,2,N+1) s.insert(i);

  ll i = 1;
  while(s.size() > 0) {
    cout << i << endl;
    ll near = 0;
    ll d = INF_LL;

    for(auto p:s) if(p != i){
      ll dp2 = (X[i] - X[p]) * (X[i] - X[p]) + (Y[i] - Y[p]) * (Y[i] - Y[p]) ;
      if(dp2 < d) {
        d = dp2;
        near = p;
      }
    }
    i = near;
    s.erase(near);
  }
  cout << i << endl;
  cout << 1 << endl;
}

int main()
{
  solve();
	return 0;
}