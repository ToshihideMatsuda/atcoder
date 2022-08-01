
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


int main()
{
    ll N; cin >> N;
    cout << (modPerm(N,N) * (modCatalan(N) * modPow(2,N) % MOD ) % MOD) << endl;
	return 0;
}