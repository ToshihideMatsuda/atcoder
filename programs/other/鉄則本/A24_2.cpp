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

#define MAX_N 100000+5


// LIS:最長増加部分列
vector<ll> dp;


void solve() {
  ll N; cin >> N;

  dp.push_back(INF_LL);
  rep(i,N){ 
    ll a;
    cin >> a;

    auto idx = lower_bound(dp.begin(), dp.end(), a);
    if(*idx == INF_LL) {
      *idx = a;
      dp.push_back(INF_LL);
    } else {
      *idx = a;
    }
  }

  ll ans = dp.size() - 1;

  cout << ans << endl;

}


int main()
{
  solve();
	return 0;
}