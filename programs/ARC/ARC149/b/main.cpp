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

#define MAX_N 2*100000+5
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

void solve() {
  ll N; cin >> N;
  vector<ll> A(N), B(N);
  rep(i,N) cin >> A[i]; 
  rep(i,N) cin >> B[i]; 

  vector<pair<ll,ll>> AB[2];
  rep(i,N) {
    AB[0].push_back({A[i], B[i]});
    AB[1].push_back({B[i], A[i]});
  }

  sort(AB[0].begin(),AB[0].end());
  sort(AB[1].begin(),AB[1].end());

  ll ans[2]; ans[0] = 0; ans[1] = 0;
  vector<ll> dp[2];
  rep(k,2) rep(i,N+5) {
    dp[k].push_back(INF_LL);
  }

  rep(k,2) rep(i,N) {
    *lower_bound(dp[k].begin(),dp[k].end(),AB[k][i].second) = AB[k][i].second;
  }
  rep(k,2) rep(i,N) if(dp[k][i] != INF_LL){
    ans[k] ++;
  }



  cout << MAX(ans[0],ans[1]) + N << endl;

}


int main()
{
  solve();
	return 0;
}