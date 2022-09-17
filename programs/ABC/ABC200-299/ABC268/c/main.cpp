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
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

void solve() {
  ll N; cin >> N;
  vector<ll> p(N);
  rep(i,N) cin >> p[i];

  vector<ll> cnt(N);
  rep(i,N) {
    cnt[(p[i] - i + (N - 1)) % N] ++;
    cnt[(p[i] - i + N      ) % N] ++;
    cnt[(p[i] - i + (N + 1)) % N] ++;
  }
  ll ans = 0;
  rep(i,N) ans = max(ans, cnt[i]);
  cout << ans << endl;


}


int main()
{
  solve();
	return 0;
}