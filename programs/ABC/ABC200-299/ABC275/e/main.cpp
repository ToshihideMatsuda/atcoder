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

#define MAX_N 2*100000+5
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

long long modPow(long long x, long long a) {
  if (a == 1) return x;
  if (a % 2) return (x * modPow(x, a - 1)) % MOD;
  long long t = modPow(x, a / 2);
  return (t * t) % MOD;
}

long long modInv(long long x) {
  return modPow(x, MOD - 2);
}

ll dp[1005][1005];

void solve() {
  ll N, M, K; cin >> N >> M >> K;

  dp[0][0] = 1;

  ll invM = modInv(M);

  reps(k,1,K+1) {
    reps(n,1,N+1) {
      ll s = 0;
      reps(m,1,M+1) {
        if(n-m >=0){
          s += (dp[k-1][n-m] * invM);
          s %= MOD;
        }
      }

      dp[k][n] = s;
      if(n == N) continue;

      s = 0;
      if(N-n <= M-1) {
        ll L = (M-1) - (N-n);
        rep(l,L+1){ 
          s += (dp[k-1][N-1-l] * invM);
          s %= MOD;
        }
      }
      dp[k][n] += s;
      dp[k][n] %= MOD;
    }
  }

  ll z= 0;
  reps(k,1,K+1) {
    z += dp[k][N];
    z %= MOD;
  }
 
  cout << z << endl;

}


int main()
{
  solve();
	return 0;
}