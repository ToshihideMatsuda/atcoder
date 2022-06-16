#include <bits/stdc++.h> 
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

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}



void solve() {
    ll N, M, K;
    cin >> N >> M >> K;

    ll dp[N + 5][M + 5];
    rep(i,N+5)rep(j,M+5) dp[i][j] = 0;
    rep(j,M+5) dp[1][j] = 1;


    reps(i, 1, N+1) {
        reps(j, 1, M +1) {
            if(j == 1) {
                ll sum = 0;
                reps(k,K,M+1) if(j+k <= M) {
                    sum += dp[i][j+k];
                    sum %= MOD;
                }
                dp[i+1][j] = sum;
            }
            else 
            {
                dp[i+1][j] = dp[i+1][j-1];

                dp[i+1][j] += (j-K >= 1   ?  dp[i][j-K]   : 0);
                dp[i+1][j] %= MOD;
                dp[i+1][j] += MOD - (j-1+K <= M ?  dp[i][j-1+K] : 0);
                dp[i+1][j] %= MOD;
            }
        } 

    }

    ll ans = 0;

    reps(j,1,M+1) {
        ans += dp[N][j];
        ans %= MOD;
    }
    cout << ans << endl;



}


int main()
{
  solve();
	return 0;
}