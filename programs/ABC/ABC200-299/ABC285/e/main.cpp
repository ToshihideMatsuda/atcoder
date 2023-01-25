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

#define MAX_N (5005)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

//dp[n][i]:左端が0に固定した状態で、n番目まで最右端0がi番目であるものの最大値
ll dp[MAX_N][MAX_N];

void solve() {
  ll N; cin >> N;
  vector<ll> A(N);
  rep(i,N) cin >> A[i];

  vector<ll> R(N); //R[n]=0123...3210のように0から0に囲まれた範囲の長さがnである場合の値
  reps(i,1,N){
    R[i] = R[i-1] + A[(i-1)/2];
  }

  dp[1][1] = 0;
  reps(n,2,N+1){
    { //n番目を0に設定する場合
      ll tmp = 0;
      reps(i,1,n) {
        tmp = MAX(tmp, dp[n-1][i]);
      }
      dp[n][n] = tmp;
    }

    { //n番目を1に設定する場合

      reps(i,1,n) {
        if((n-1-i)/2 >= 2) {
          ll a = 0;
        } 
        dp[n][i] = dp[n-1][i] + A[(n-1-i)/2];
      }
    }
  }

  ll ans = 0;
  reps(i,1,N+1) {
    ans = MAX(ans,dp[N][i]);
  }

  out(ans)


}


int main()
{
  solve();
	return 0;
}