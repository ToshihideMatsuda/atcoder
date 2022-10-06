
typedef long long ll;
#define MOD 998244353

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

ll modPerm(ll n, ll k) {
  ll ret = 1;
  for (ll i = 0; i < k; i++) {
    ret = (ret * (n - i)) % MOD;
  }
  return ret;
}

ll modComb(ll n, ll k) {
  ll a, b;
  a = modPerm(n, k);
  b = modPerm(k, k);
  return (a * modInv(b)) % MOD;
}

ll modCatalan(ll n) {
  ll a  = modComb(2*n, n);
  return (a * modInv(n+1))  % MOD;
}

