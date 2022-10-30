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

ll dp[MAX_N], A[MAX_N], B[MAX_N];


void solve() {
  ll N; cin >> N;

  reps(i,1,N) cin >> A[i];
  reps(i,1,N) cin >> B[i];

  reps(i,1,MAX_N) dp[i] = -1;
  dp[1] = 0;
  reps(i,1,N) {
    if(dp[i] > 0) {
      dp[A[i]] = max(dp[A[i]], dp[i] + 100);
      dp[B[i]] = max(dp[B[i]], dp[i] + 150);
    }
  }

  cout << dp[N] << endl;


}


int main()
{
  solve();
	return 0;
}