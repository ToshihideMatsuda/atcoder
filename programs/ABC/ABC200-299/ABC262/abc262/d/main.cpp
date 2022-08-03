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

#define MAX_N 100+5

//dp[i][j][m][v] = i番目まで見た時にj個選択。その場合の % m = w の通り数
ll dp[MAX_N][MAX_N][MAX_N][MAX_N];


void solve() {
  ll N;  cin >> N;
  vector<ll> a(N+1); rep(i,N) cin >> a[i+1] ;
  
  reps(m,1,N+1) dp[0][0][m][0] = 1;
  reps(i,1,N+1) {
    rep(j,i+1) {
        // not select 
        reps(m,1,N+1) rep(w,N)  
        {
            dp[i][j][m][w] += dp[i-1][j][m][w]; 
            dp[i][j][m][w] %= MOD;
        }

        // select
        reps(m, 1, N+1) rep(w,N) {
            if (j > 0) {
                dp[i][j][m][ (w + a[i]) % m] += dp[i-1][j-1][m][w] ; 
                dp[i][j][m][ (w + a[i]) % m] %= MOD;
            }
        }
    }
  }

  ll ans = 0;

  reps(j,1,N+1) {
    ans += dp[N][j][j][0];
    ans %= MOD;
  }

  cout << ans << endl;
}


int main()
{
  solve();
	return 0;
}