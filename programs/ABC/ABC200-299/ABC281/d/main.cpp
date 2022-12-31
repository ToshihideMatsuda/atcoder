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

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


void solve() {
  ll N, K, D; cin >> N >> K >> D;
  vector<ll> A(N+1); reps(i, 1,N+1) cin >> A[i];

  vector dp(N+1,vector(K+1,vector<long long>(D,-1)));
  // dp[n][k][d] : nまで見た時にk個選んだ際の%Dでの最大値
  // dp[n+1][k][d] = max(dp[n][k][m],dp[n][k-1][d'] + A_{n+1})
  dp[0][0][0] = 0;

  rep(n,N){ 
    rep(k,K+1) {
      rep(d,D) {

        if(dp[n][k][d] == -1) continue;

        //A[n] を選ばない場合の遷移
        dp[n+1][k][d]   = MAX(dp[n+1][k][d],dp[n][k][d]);

        //A[n] を選ぶ場合の遷移
        if(k != K) {
          ll d2 = (d  + A[n+1] ) % D;
          dp[n+1][k+1][d2] = MAX(dp[n][k][d2],dp[n][k][d] + A[n+1]);
        }
        
      }
    }
  }

  cout << dp[N][K][0] << endl;

}


int main()
{
  solve();
	return 0;
}