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

ll dp[100+1][100000+1];

void solve() {
  ll N, W; cin >> N >> W;
  ll w[N+1], v[N+1]; reps(i,1,N+1) cin >> w[i] >> v[i];
  rep(n,N+1)rep(w,W+1) dp[n][w] = -1;
  rep(n,N+1)dp[n][0] = 0;

  reps(n,1,N+1){
    reps(cw,1,W+1) {
      if (cw-w[n] >= 0 && dp[n-1][cw-w[n]] >= 0) {
        dp[n][cw] = max(dp[n-1][cw-w[n]] + v[n], dp[n-1][cw]);
      } else {
        dp[n][cw] = dp[n-1][cw];
      }
    }
  }

  ll ans = 0;
  reps(w,1,W+1) ans = MAX(ans,dp[N][w]);
  
  cout << ans << endl;

}


int main()
{
  solve();
	return 0;
}