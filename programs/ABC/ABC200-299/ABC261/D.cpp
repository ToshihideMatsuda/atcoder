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

#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5

 // dp[i][c]
ll dp[5005][5005];

void solve() {
  ll N, M; cin >> N >> M;
  vector<ll> X(N+1); rep(i,N) cin >> X[i+1];
  vector<ll> Y(5005);
  rep(i,M) {
    ll c, y;
    cin >> c >> y;
    Y[c] = y;
  }

  dp[0][0] = 0;

  reps(i,1,N+1) {
    ll m = 0;
    rep(j, 5005) m = max(m,dp[i-1][j]);

    dp[i][0] = m;
    reps(j,1,5005) {
      if(j == 1) {
        dp[i][j] = dp[i-1][j-1] +  X[i] + Y[j];
      } else {
        dp[i][j] = dp[i-1][j-1];
        if(dp[i-1][j-1] > 0) dp[i][j] += X[i] + Y[j];
      }
    }
  }

  ll ans = 0;
  rep(j,5005) ans = max(ans, dp[N][j]);
  cout << ans << endl;


}


int main()
{
  solve();
	return 0;
}