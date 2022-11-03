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

#define MAX_N 300000 + 5

bool prime[300000 + 5];

ll modPow(ll a, ll b, ll mod) {
  ll ans = 1;

  for(ll i = 63; i > -1; i--) {
    ans *= ans;
    ans %= mod;
    if( (b >> i) % 2 == 1) {
      ans *= a;
      ans %= mod;
    }
  }
  return ans;
}

void solve() {
  ll a,b; cin >> a >> b;
  ll mod = 1000000007;
  cout << modPow(a,b,mod) << endl;

}


int main()
{
  solve();
	return 0;
}