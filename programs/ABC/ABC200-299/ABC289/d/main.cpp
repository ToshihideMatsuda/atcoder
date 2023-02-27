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

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

void solve() {
  ll N; cin >> N;
  vector<ll> A(N); rep(i,N) cin >> A[i];
  ll M; cin >> M;
  set<ll> B; rep(i,M){ 
    ll b;
    cin >> b;
    B.insert(b);
  }
  ll X; cin >> X;

  vector<bool> dp(X+1);
  
  dp[0] = true;
  rep(i,X) {
    rep(n,N) {
      if(dp[i]) if(i + A[n] <= X) if(!B.count(i + A[n])) {
        dp[i + A[n]] = true;
      }
    }
  }
  if(dp[X]) out("Yes")
  else out("No")


}


int main()
{
  solve();
	return 0;
}