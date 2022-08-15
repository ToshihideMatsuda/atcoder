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
#define MOD 1000000000 + 7

#define MAX_N 2*100000+5


void solve() {
  ll N; cin >> N;
  string S; cin >> S;
  S = "*" + S;
  string a = "atcoder";
  ll dp[N+5][8];
  rep(i,N+5)rep(j,8) dp[i][j] = 0;

  rep(i,N+5)dp[i][0] = 1;

  reps(i,1,N+1){
    rep(j,8) dp[i][j] = dp[i-1][j];
    rep(j,a.size()) if(S[i] == a[j]) {
      dp[i][j+1] += dp[i-1][j];
      dp[i][j+1] %= MOD;
    }
  }
  cout << dp[N][7] << endl;

}


int main()
{
  solve();
	return 0;
}