

#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

// 等差級数を求める
// A_1 = a
// A_i = a + (i-1) * d
// return A_1 + A_2 + ... + A_{num}
ll arithmetic_sum( ll a ,ll d, ll n){
  ll l   = (a+(n-1)*d)%MOD;
  ll res = (a+l)%MOD;
  res *= n;   res%=MOD;
  res *= INV2; res%=MOD;
  return res;
}