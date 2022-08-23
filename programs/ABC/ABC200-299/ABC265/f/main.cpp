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

ll dp[105][1005];

void solve() {
  ll N, D; cin >> N >> D;
  vector<ll> p(N+1), q(N+1);
  rep(i,N)cin >> p[i+1];
  rep(i,N)cin >> q[i+1];


  dp[0][0] = 1;

  reps(i, 1, N+1) {


    for(ll s = - 1001; s < 1001; s++) {
    ll dd = abs(p[i] - s) + abs(s- q[i]);
    rep(d,D+1) {
      if(d - dd >= 0) {
        dp[i][d] = dp[i-1][d] + dp[i][d-dd];
      } else {
         dp[i][d] = dp[i-1][d];
      }
      dp[i][d] %= MOD;
    }
    }
  }

  ll ans = 0;
  rep(i,D+1) {
    ans += dp[N][i];
    ans %= MOD;
  }

  cout << ans << endl;



}


int main()
{
  solve();
	return 0;
}