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

#define MAX_N 2*100000+5

struct pair_hash
{
    std::size_t operator() (const std::pair<ll, ll> &pair) const {
        return std::hash<ll>()(pair.first) + std::hash<ll>()(pair.second) * 99824354423518553;
    }
};

void solve() {
  ll N, M;
  cin >> N >> M;
  pair<ll,ll> d[3];
  rep(i,3) {
    cin >> d[i].first >> d[i].second;
  }

  set<pair<ll, ll>> XY;
  rep(i,M) {
    ll x, y;
    cin >> x >> y;
    XY.insert({x,y});
  }

  unordered_map<pair<ll,ll>,ll, pair_hash> dp[301]; // dp[n][x][y] = n回目で(x,y)にいる通り数
  dp[0][{0,0}] = 1;

  reps(n,1,N+1) {
    unordered_map<pair<ll,ll>,ll, pair_hash> mp;
    for(auto idx = dp[n-1].begin(); idx != dp[n-1].end(); idx++) {
      pair<ll,ll> p = idx->first;
      ll x, y; tie(x,y) = p;
      ll cnt = idx->second;

      rep(i,3) {
        pair<ll,ll> xy = { x + d[i].first, y  + d[i].second };
        if( !XY.count( xy )) {
          mp[xy] += cnt;
          mp[xy] %= MOD;
        }
      }
    }
    dp[n] = mp;
  }

  ll ans = 0;
  for(auto idx = dp[N].begin(); idx != dp[N].end(); idx++) {
    ans += idx->second;
    ans %= MOD;
  }

  cout << ans << endl;


}


int main()
{
  solve();
	return 0;
}