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

// dp[l][r] :　区間[l,r]が残存している場合の最大値
// dp[l][r] = max(dp[l-1][r] + s_i, dp[l][r+1] + s_j )
ll dp[2000+5][2000+5];

void solve() {
  ll N; cin >> N;
  vector<ll> P(N+1), A(N+1);
  rep(i,N) {
    cin >> P[i+1] >> A[i+1];
  }

  dp[1][N] = 0;

  rev(len,N-2) {
    reps(l,1,N-len+1) {
      ll r = l + len;

      ll si = (l <= P[l-1] && P[l-1] <= r) ? A[l-1] : 0;
      ll sj = (l <= P[r+1] && P[r+1] <= r) ? A[r+1] : 0;
      dp[l][r] = max(dp[l-1][r] + si, dp[l][r+1] + sj);
    }
  }

  ll ans = 0;
  reps(i,1,N+1) ans = max(ans,dp[i][i]);
  cout << ans << endl;



}


int main()
{
  solve();
	return 0;
}