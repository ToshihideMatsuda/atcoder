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

ll h(ll ch) {
  return (3276723*ch + 65762123) % MOD;
}

void solve() {
  ll N, Q; cin >> N >> Q;
  string S; cin >> S;

  ll sub[N+1];
  sub[0] = 0;

  rep(i,N) {
    sub[i+1] = (sub[i] + h(S[i] - 'a') + MOD)% MOD;
  }

  rep(i,Q) {
    ll a, b ,c, d; cin >> a >> b >> c >> d;

    ll S1 = (sub[b] - sub[a-1] + MOD)% MOD;
    ll S2 = (sub[d] - sub[c-1] + MOD)% MOD;
    if(S1 == S2) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }

  }





}

int main()
{
  solve();
	return 0;
}