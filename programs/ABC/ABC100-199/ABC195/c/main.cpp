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

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }



void solve() {

  ll N; cin >> N;

  ll cnt[18];
  cnt[0] = 0;
  reps(i,1,18) {
    cnt[i] = cnt[i-1];
    if(i%3 == 1 && i > 1) {
      cnt[i] += 1;
    }
  } 

  ll ten[18];
  ten[0] = 1;
  reps(i,1,18) ten[i] = ten[i-1]*10;
  
  ll ans = 0;
  
  ll j = 0;
  reps(i,1,18) if(N < ten[i]) {
    j = i;
    break;
  }

  // N < 10^j
  // 10^(j-1) ~ N まで
  ans += cnt[j] *(N - ten[j-1] + 1);
  reps(k,4,j) 
    ans += cnt[k] *(ten[k] - ten[k-1]);

  cout << ans << endl;

}


int main()
{
  solve();
	return 0;
}