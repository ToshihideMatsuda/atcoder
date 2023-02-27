#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) MIN(a,MIN(b,c))
#define out(s) cout << s << endl;
#define out2(s) cout << s;

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
ll dp[MAX_N + 5][2];
void solve() {
  ll N; cin >> N; 
  vector<ll> A(N+1), B(N+1);
  rep(i,N) {
    cin >> A[i+1] >> B[i+1];
  }

  
  rep(i,N+5){
    dp[i][0] = 0;
    dp[i][1] = 0;
  }

  dp[1][0] = 1;
  dp[1][1] = 1;

  reps(i,2,N+1) {

    ll dp0 = 0;
    ll dp1 = 0;
    if(A[i] != A[i-1]) {
      dp0 += dp[i-1][0];
    } 
    if(A[i] != B[i-1]) {
      dp0 += dp[i-1][1];
    }


    if(B[i] != A[i-1]) {
      dp1 += dp[i-1][0];
    } 
    if(B[i] != B[i-1]) {
      dp1 += dp[i-1][1];
    }

    dp[i][0] = dp0;
    dp[i][0] %= MOD;
    dp[i][1] = dp1;
    dp[i][1] %= MOD;

  }

  ll ans = (dp[N][1] + dp[N][0]) % MOD;
  out(ans)


}



int main()
{
  solve();
	return 0;
}