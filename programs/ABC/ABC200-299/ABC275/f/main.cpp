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
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

// dp[n][x][k] = n/Nまで見た場合に選ぶ数がxとなり、かつ、末尾の選択がk(0/1)
// dp[n][x][0] = min(dp[n-1][x][1]+1, dp[n-1][x][0]);
// dp[n][x][1] = min(dp[n-1][x-A[n][1], dp[n-1][x-A[n][0] + 1 );
ll dp[3005][3005][2];

void solve() {
  ll N, M; cin >> N >> M;

  vector<ll> A(N+1);
  rep(i,N) cin >> A[i+1];
 
  rep(n,N+1)rep(x,M+1) {
    dp[n][x][0] = INF_LL;
    dp[n][x][1] = INF_LL;
  }

  dp[0][0][1] = 0;

  reps(n,1,N+1) {
    rep(x,M+1) {
      dp[n][x][0] = MIN(dp[n-1][x][1] + 1, dp[n-1][x][0]);
      if(x-A[n] >= 0) {
        dp[n][x][1] = MIN(dp[n-1][x-A[n]][1],dp[n-1][x-A[n]][0]);
      }
    }
  }

  reps(x,1,M+1) {
    ll ans = MIN(dp[N][x][0], dp[N][x][1]);
    if(ans >= INF_LL) cout << -1 << endl;
    else cout << ans << endl;
  }
}


int main()
{
  solve();
	return 0;
}