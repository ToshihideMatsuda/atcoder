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

#define MAX_N 2*100000+5
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

void solve() {
  ll N, S; cin >> N >> S;
  ll A[N+1]; reps(i,1,N+1) cin >> A[i];
  bool dp[N+1][S+1]; 
  rep(n,N+1)rep(s,S+1) dp[n][s] = false;
  rep(n,N+1) dp[n][0] = true;

  reps(i,1,N+1){
    rep(s,S+1) {
      if(s < A[i])  dp[i][s] = dp[i-1][s];
      else { // A[i] <= s
        if(dp[i-1][s] || dp[i-1][s-A[i]] ) dp[i][s] = true;
        else dp[i][s] = false;
      }
    }
  }
  
  cout << (dp[N][S] ? "Yes":"No") << endl;

}


int main()
{
  solve();
	return 0;
}