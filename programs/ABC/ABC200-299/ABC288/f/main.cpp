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

void solve() {
  ll N; cin >> N;
  string S; cin >> S;

  // dp[i]:1~i文字目まで見た場合の解とおくと、以下の等式が成立
  // dp[i]	=	dp[i-1] * S[i:i]   + 
  //          dp[i-2] * S[i-1:i] + ...
  //          dp[1]   * S[2:i]   +
  //          dp[0]   * S[1:i] 
  //
  // ここで、j < iにおいて、S[j:i] = 10 * S[j:i-1] + S[i:i]となるので、上記を変形して、
  // dp[i]  =	dp[i-1] * (10*0          + S[i:i]) + 
  //          dp[i-2] * (10*S[i-1:i-1] + S[i:i]) + ...
  //          dp[1]   * (10*S[2  :i-1] + S[i:i]) + 
  //          dp[0]   * (10*S[1  :i-1] + S[i:i]) 
  //        = dp[i-1] * (10*0          + S[i:i]) + 
  //          10 * dp[i-1] +     Σ(j=0...i-2)dp[j]*S[i:i]
  //        = 10 * dp[i-1] +     Σ(j=0...i-1)dp[j]*S[i:i]
  // よって、累積和R[i] = Σ(j=0...i)dp[j]とすると、以下のような式となる。
  // dp[i]  = 10 * dp[i-1] + R[i-1] * S[i:i]
  vector<ll> dp(N+1);
  vector<ll> R(N+1);

  dp[0] = 1;
  dp[1] = S[0] - '0';
  
  R[0] = dp[0];
  R[1] = dp[1] + R[0];

  reps(i,2,N+1) {
    dp[i] = 10*dp[i-1] + R[i-1] * (S[i-1] - '0');
    dp[i] %= MOD;

    R[i] = dp[i] + R[i-1];
    R[i] %= MOD;
  }

  out(dp[N]);

}


int main()
{
  solve();
	return 0;
}