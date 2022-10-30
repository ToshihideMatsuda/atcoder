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

ll dp[1024+5];


void solve() {
  ll N, M; cin >> N >> M;
  vector<ll> A;
  rep(i,M) {
    ll tmp = 0;
    rep(i,N) {
      ll a;
      cin >> a;
      tmp += a * (1 << i);
    }
    // 2^10程度（1024）
    A.push_back(tmp);
  }

  rep(i,1024+3) dp[i] = INF_LL;
  dp[0] = 0;

  rep(i,1 << N) {
    for(auto a:A) {
      dp[i|a] = min(dp[i|a], dp[i] + 1);
    }
  }

  ll ans = 0;
  rep(i,N){
    ans += (1 << i);
  }

  if(dp[ans] < INF_LL) cout << dp[ans] << endl;
  else cout << -1 << endl;

}


int main()
{
  solve();
	return 0;
}