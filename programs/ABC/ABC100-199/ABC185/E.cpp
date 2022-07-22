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

#define MAX_N 2*100000+5

ll N, M; 
vector<ll> A, B;

//dp[i][j] = A[1],...,A[i]とB[1],....,B[j]になった場合の値
ll dp[1005][1005];


void solve() {
  cin >> N >> M;
  A.resize(N+1);
  B.resize(M+1);

  rep(i,N) cin >> A[i+1];
  rep(i,M) cin >> B[i+1];

  rep(i,N+1) dp[i][0] = i;
  rep(j,M+1) dp[0][j] = j;

  reps(i,1,N+1)reps(j,1,M+1){
    dp[i][j] = min3(
      dp[i-1][j] + 1,                           // A[i]を消す
      dp[i][j-1] + 1,                           // B[j]を消す
      dp[i-1][j-1] + ( (A[i] == B[j]) ? 0 : 1)  // 両方残す
    );
  }

  cout << dp[N][M] << endl;



}


int main()
{
  solve();
	return 0;
}