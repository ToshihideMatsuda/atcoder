#include <bits/stdc++.h> 

using namespace std;

#define debug false

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define max(a,b)   (a>b?a:b)
#define max3(a,b,c) max(a,max(b,c))
#define min(a,b)   (a<b?a:b)
#define min3(a,b,c) min(a,min(b,c))

#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 1000000000+7

#define MAX_N 1000+5

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}
void UNSOLVABLE() {
  cout << "UNSOLVABLE" << endl;
}


ll dp[MAX_N][MAX_N];
ll X[MAX_N][MAX_N];
ll A[MAX_N][MAX_N];
ll Tr[2][MAX_N][MAX_N];

void clear_dp() {
  rep(i,MAX_N)  rep(j,MAX_N)  dp[i][j] = INF_LL;
}

void clear_X() {
  rep(i,MAX_N)  rep(j,MAX_N)  X[i][j] = INF_LL;
}

void solve(){
  ll H, W, C;
  cin >> H >> W >> C;
  
  rep(h,H) rep(w,W) cin >> A[h+1][w+1];
  rep(h,H) rep(w,W) Tr[0][h+1][w+1] = A[h+1][w+1];        // そのままの位置
  rep(h,H) rep(w,W) Tr[1][h+1][w+1] = A[h+1]  [W - w];   // 左右反転 ok
  //rep(h,H) rep(w,W) Tr[1][h+1][w+1] = A[H - h][w+1];   // 上下反転 ok
  //rep(h,H) rep(w,W) Tr[1][h+1][w+1] = A[H - h][W - w]; // 上下左右反転 ng

  ll ans = INF_LL;

  rep(tr,2) {
    
    //転記して実施（以降では左上が起点となるロジックなので上下反転 or 左右反転のいずれかを実施する必要あり）
    rep(h,MAX_N) rep(w,MAX_N) A[h][w] = Tr[tr][h][w];
  
    clear_dp();
    clear_X();

    reps(h,1,H+1) reps(w,1,W+1) {
      // dp[h][w]: (h,w)よりも左上で街を１つ配置した状態で、(h,w)まで線路を配置した場合の最小値
      dp[h][w] = min3(A[h][w], 
                      dp[h-1][w]+C, 
                      dp[h][w-1]+C);
    }

    reps(h,1,H+1) reps(w,1,W+1) {
      // X[h][w]: (h,w)にて２つ目の街を配置した場合の最小値
      X[h][w] = min(dp[h-1][w] + C + A[h][w], 
                    dp[h][w-1] + C + A[h][w]);
    }

    // 一番最小の値を取得
    reps(h,1,H+1) reps(w,1,W+1) ans = min(ans, X[h][w]);

  }

  cout << ans << endl;



}



int main(){
    solve();
    return 0;
}
