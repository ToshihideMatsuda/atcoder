
typedef long long ll;
#define MOD 998244353

ll modPow(ll x, ll a) {
  if (a == 1) return x;
  if (a % 2) return (x * modPow(x, a - 1)) % MOD;
  ll t = modPow(x, a / 2);
  return (t * t) % MOD;
}

ll modInv(ll x) {
  return modPow(x, MOD - 2);
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

