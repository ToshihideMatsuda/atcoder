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




long long modPow(long long x, long long a) {
  if (a == 0) return 1;
  if (a == 1) return x;
  if (a % 2) return (x * modPow(x, a - 1)) % MOD;
  long long t = modPow(x, a / 2);
  return (t * t) % MOD;
}
long long modInv(long long x) {
  return modPow(x, MOD - 2);
}

ll dp[MAX_N];
// dp[N] = 0;
// dp[N-1] = 1;
// dp[N-2] = P/100  + (1 - P/100) * 2:
// dp[N-3] = P/100 * (dp[N-1]+1) + (1- P/100) * (dp[N-2]+1);

void solve() {
  ll N, P; cin >> N >> P;

  ll inv = modInv(100);

  ll p = (P * inv ) % MOD;
  ll q = (1 - P * inv ) % MOD;
  while(q < 0) {
    q += MOD;
  }

  dp[N] = 0;
  dp[N-1] = 1;

  for(ll n = N-2; n > -1; n--) {
    dp[n] = ( p * (dp[n+2] + 1) + q * (dp[n+1] + 1) ) % MOD;
  }

  cout << dp[0] << endl;


}


int main()
{
  solve();
	return 0;
}