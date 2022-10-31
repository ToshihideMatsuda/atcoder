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

#define MAX_N 100000+5



void solve() {
  ll H, W; cin >> H >> W;
  char C[H+1][W+1];
  rep(w,W+1) C[H][w] = '#';
  rep(h,H+1) C[h][W] = '#';

  rep(h,H)rep(w,W) cin >> C[h][w];
  ll dp[H][W];
  rep(h,H)rep(w,W) dp[h][w] = 0;

  dp[0][0] = 1;

  //配るDP
  /*
  rep(h,H){
    rep(w,W) {
      // 地点(h,w) から、地点(h,w+1)、(h+1,w)に値を配る遷移
      if(C[h][w+1] == '.') dp[h][w+1] += dp[h][w];
      if(C[h+1][w] == '.') dp[h+1][w] += dp[h][w];
    }
  }
  */

  //貰うDP
  rep(h,H){
    rep(w,W) if(C[h][w] == '.') {
      // 地点(h,w)に、地点（h-1,w)、(h,w-1)から値を貰う遷移
      if(h > 0) dp[h][w] += dp[h-1][w];
      if(w > 0) dp[h][w] += dp[h][w-1];
    }
  }

 
  cout << dp[H-1][W-1] << endl;

}


int main()
{
  solve();
	return 0;
}