typedef long long ll;
#define MOD 998244353

#include <iostream>
#include <cmath>
using namespace std;

ll modPow(ll x, ll a,ll mod) {
  if(x >= mod) { x %= mod; }

  if (a == 0) return 1;
  if (a == 1) return x;
  if (a % 2) return (x * modPow(x, a - 1,mod)) % mod;
  ll t = modPow(x, a / 2,mod) % mod;

  return (t * t) % mod;
}

int main(){
	ll n,k,m;cin>>n>>k>>m;
  ll ans = 0;
  if( (m%MOD) >= 1 ) {
	  ll p = modPow(k, n, MOD-1);
	  ans = modPow(m, p ,MOD);
  }
	cout<<ans<<endl;
	return 0;
	
}
