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
  ll N;
  cin >> N;

  vector<ll> A(N+5);
  rep(i,N) cin >> A[i+1];
  A[N+1] = A[1];

  ll dp[N+5];

  //1を選択した場合
  {
    rep(i,N+5) dp[i] = INF_LL;
    dp[1] = A[1];

    reps(k, 1, N+1) {
      dp[k+1] = min(dp[k+1], dp[k] + A[k+1]); // A_k+1 select
      dp[k+2] = min(dp[k+2], dp[k] + A[k+2]); // A_k+2 select
    }
  }
  ll ans = min(dp[N-1],dp[N]);

  //1を選択しなかった場合
  {
    rep(i,N+5) dp[i] = INF_LL;
    dp[1] = A[N];
    dp[2] = dp[1] + A[2];

    reps(k, 2, N+1) {
      dp[k+1] = min(dp[k+1], dp[k] + A[k+1]); // A_k+1 select
      dp[k+2] = min(dp[k+2], dp[k] + A[k+2]); // A_k+2 select
    }
  }

  ans = min(ans,min(dp[N-1],dp[N-2]));




  cout << ans << endl;
  

}


int main()
{
  solve();
	return 0;
}