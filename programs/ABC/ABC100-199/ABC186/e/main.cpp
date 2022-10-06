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

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N 2*100000+5

ll euler_phi(ll n) {
  ll ret = n;
  for(ll i = 2; i * i <= n; i++) {
    if(n % i == 0) {
      ret -= ret / i;
      while(n % i == 0) n /= i;
    }
  }
  if(n > 1) ret -= ret / n;
  return ret;
}

ll MOD = 1;
long long modPow(long long x, long long a) {
  if (a == 0) return 1;
  if (a == 1) return x;
  if (a % 2) return (x * modPow(x, a - 1)) % MOD;
  long long t = modPow(x, a / 2);
  return (t * t) % MOD;
}

long long modInv(long long x) {
  return modPow(x, euler_phi(MOD) - 1);
}

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}


void solve() {
  ll T; cin >> T;
  rep(_,T) {
    ll N, S, K; cin >> N >> S >> K;
    // 0 = S + n*K mod N の nを求める <=> (N-S) = (n*K) mod N

    ll g = gcd(gcd(K,N), N-S);
    
    ll A = K/g;
    ll B = (N-S)/g;
    ll M = N/g;

    
    if(gcd(A,M) == 1) {
        MOD = M;
        ll invA = modInv(A);
        cout << (invA * B) % M << endl;
      continue; 
    } 
    cout << -1 << endl;
  }
}


int main()
{
  solve();
	return 0;
}