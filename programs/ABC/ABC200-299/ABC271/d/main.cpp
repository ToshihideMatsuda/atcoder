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

// dp[n][s] = n文字目までで値sが可能であるか否か
bool dp[109][10009];

void solve() {
  ll N, S; cin >> N >> S;
  vector<ll> A(N), B(N);
  rep(i,N) cin >> A[i] >> B[i];

  dp[0][0] = true;

  reps(n,1,N+1) {
    reps(s,1,S+1) {
      if(s-A[n-1]>=0) dp[n][s] |= dp[n-1][s-A[n-1]];
      if(s-B[n-1]>=0) dp[n][s] |= dp[n-1][s-B[n-1]];
    }
  }

  if(dp[N][S]){
    cout << "Yes" << endl;
    ll s = S;
    vector<char> HT(N);
    for(ll n = N-1 ; n > -1; n--){
      if(s - A[n] >= 0 &&  dp[n][s - A[n]]) {
        s -= A[n];
        HT[n] = 'H';
      } else if(s - B[n] >= 0 && dp[n][s - B[n]]) {
        s -= B[n];
        HT[n] = 'T';
      }
    }
    rep(i,N) cout << HT[i];
    cout << endl;
  } else {
    cout << "No" << endl;
  }
}


int main()
{
  solve();
	return 0;
}