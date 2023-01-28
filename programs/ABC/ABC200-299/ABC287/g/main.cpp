#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) MIN(a,MIN(b,c))
#define out(s) cout << s << endl;
#define out2(s) cout << s;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N 10//(5000+10)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

ll N; 
ll dp[2][MAX_N][MAX_N];
void dfs(ll p){

  if(G[p].size() == 1 && ck[G[p][0]]) { //末端
    dp[1][p][1] += 1;
    dp[1][p][1] %= MOD;
    return;
  }

  for(auto q: G[p]) {
    if(ck[q] == false) {
      ck[q] = true;
      dfs(q);

      if(p == 2) {
        ll a = 0;
      }

      reps(i,1,N+1) {
        dp[0][p][i] += dp[1][q][i] + dp[0][q][i];
        dp[1][p][i] += dp[1][q][i] + dp[0][q][i-1];
        dp[0][p][i] %= MOD;
        dp[1][p][i] %= MOD;
      }
    }
  }
}


void solve() {
  cin >> N;
  readG(N-1);
  ck[1] = true;
  dfs(1);

  reps(i,1,N+1) {
    out(dp[0][1][i] + dp[1][1][i])
  }

}


int main()
{
  solve();
	return 0;
}