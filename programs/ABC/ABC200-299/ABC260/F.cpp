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
  ll S, T, M; cin >> S >> T >> M;
  vector<ll> v(M), u(M);
  vector<ll> L[S+5];

  rep(i,M) cin >> u[i] >> v[i];
  rep(i,M) L[u[i]].push_back(v[i] - S);

  ll Mt[T+5][T+5];
  rep(i,T+5) rep(j,T+5) Mt[i][j] = -1;

  rep(i,S+1) {
    if( L[i].size() < 2) continue;
    for(ll x: L[i]) for(ll y : L[i])if(x < y) {
      if(Mt[x][y] == -1) {
        Mt[x][y] = i;
      } else {
        cout << x + S<< " ";
        cout << Mt[x][y] << " ";
        cout << y + S<< " ";
        cout << i << endl;
        return;
      }
    }
  }

  cout << -1 << endl;




}


int main()
{
  solve();
	return 0;
}