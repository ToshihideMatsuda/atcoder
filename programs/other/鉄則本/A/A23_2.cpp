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

#define MAX_N 100000+5

ll A[105][15];

// dp[i][S]: i番目見た時の集合Sにする際の最小のチケット数
ll dp[105][1024+5];


void solve() {
  ll N, M; cin >> N >> M;
  reps(i,1,M+1)reps(j,1,N+1) cin >> A[i][j];
  rep(i,M+1)rep(j,(1 << N) + 2) dp[i][j] = INF_LL;

  dp[0][0] = 0;
  reps(i,1,M+1) {
    rep(S,1 << N) {

      // Sのビットを取得
      bool Sbit[15];
      reps(k,1,N+1) {
        ll k_Keta = (S/(1 << (k-1)))%2;
        Sbit[k] = (k_Keta == 1);
      }

      // すでにSで1になっているビットとA[i]のビットのorをとって vとして登録
      ll v = 0;
      reps(k,1,N+1) {
        if(Sbit[k] == 1 || A[i][k] == 1) v += (1 <<(k-1));
      }

      dp[i][S] = min(dp[i][S],dp[i-1][S]);     // i番目を選ばなかった場合
      dp[i][v] = min(dp[i][v],dp[i-1][S] + 1); // i番目を選んだ場合

    }
  }

  if( dp[M][(1 << N)-1] == INF_LL ) cout << -1 << endl;
  else cout << dp[M][(1 << N)-1] << endl;

}


int main()
{
  solve();
	return 0;
}