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
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N 10000 + 5
#define MAX_K 100 + 5
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

//dp[n][k] = max_{j}( dp[n-A[k]][j] + A[k] )
ll dp[MAX_N][MAX_K];

void solve() {
  ll N, K; cin >> N >> K;
  vector<ll> A(K); rep(k,K) cin >> A[k];

  reps(n,1,N+1) {
    if(n==5) {
      int i = 0;
    }
    rep(k,K) {
      ll tmp = 0;
      if(n - A[k] == 0) {
        rep(j,K) tmp = MAX(tmp, dp[n-A[k]][j] + A[k]); 
      } else if(n - A[k] > 0){
        ll tmp2 = 0;
        ll k0 = 0;
        rep(j,K) if(tmp2 < dp[n-A[k]][j]) {
          tmp2 = dp[n-A[k]][j];
          k0 = j;
        }
        if(n-A[k]-A[k0] >= 0) {
          rep(j,K) tmp = MAX(tmp, dp[n-A[k]-A[k0]][j] + A[k]); 
        }
      }
      dp[n][k] = tmp;
    }
  }
  

  ll ans = 0;
  rep(k,K) ans = max(ans, dp[N][k]);
  cout << ans << endl;


}


int main()
{
  solve();
	return 0;
}