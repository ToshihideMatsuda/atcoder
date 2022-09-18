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

#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD


ll N, M, Q; 
bool even(ll i, ll j) {
  return ((i%2 + j%2) % 2) == 0;
}

ll f(ll i, ll j) {
  return ( (M * (i-1)) + j )%MOD;
} 

// 等差級数を求める
// A_1 = a
// A_i = a + (i-1) * d
// return A_1 + A_2 + ... + A_{num}
ll arithmetic_sum( ll a ,ll d, ll n){
  if(n <= 0) return 0;
  ll l   = (a+(n-1)*d)%MOD;
  ll res = (a+l)%MOD;
  res *= n;   res%=MOD;
  res *= INV2; res%=MOD;
  return res;
}

pair<ll,ll> rowSumCnt(ll x, ll l, ll r) {
  if((x+l) % 2 == 1) l++;
  if((x+r) % 2 == 1) r--;
  if(r < l) return {0,0}; //sum,cnt

  ll n = 1 + (r-l)/2;
  ll a = f(x,l);
  ll s = arithmetic_sum(a,2,n);

  return {s,n};

}

void solve() {
  cin >> N >> M >> Q;

  rep(i, Q) {
    ll A, B, C, D; 
    cin >> A >> B >> C >> D;

    ll m0 = 0, m1 =0, l0 = 0, l1 = 0;
    tie(l0 ,m0) = rowSumCnt(A,C,D);
    tie(l1 ,m1) = rowSumCnt(A+1,C,D);

    ll ans = 0;
    ll n0 = (B-A+1)/2 + (B-A+1)%2;
    ans += arithmetic_sum(l0, (((2*M)%MOD)*m0)%MOD, n0);
    ans %= MOD;

    ll n1 = (B-A+1)/2;
    ans += arithmetic_sum(l1, (((2*M)%MOD)*m1)%MOD, n1);
    ans %= MOD;
    
    cout << ans << endl;
    
  }

}


int main()
{
  solve();
	return 0;
}