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
  ll N; cin >> N;
  ll A[N+1], B[N+1];
  reps(i,2,N+1) cin >> A[i];
  reps(i,3,N+1) cin >> B[i];
  ll dp[N+1];  
  ll from[N+1];  
  dp[1] = 0; from[1] = -1;
  dp[2] = A[2]; from[2] = 1;
  reps(i,3,N+1){
    if(dp[i-1]+A[i] < dp[i-2]+B[i]) {
      from[i] = i-1;
      dp[i]   = dp[i-1]+A[i];
    } else {
      from[i] = i-2;
      dp[i]   = dp[i-2]+B[i];
    }
  }
  vector<ll> P;
  P.push_back(N);
  while(true) {
    if(from[P.back()] == -1){
      break;
    } else {
      P.push_back(from[P.back()]);
    }
  }
  reverse(P.begin(),P.end());
  cout << P.size() << endl;
  rep(i,P.size()) cout << P[i] << " ";

}


int main()
{
  solve();
	return 0;
}