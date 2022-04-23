#include <bits/stdc++.h> 

using namespace std;

#define debug false

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 



#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#if debug == true
    #define MAX_N 100 + 5
#else
    #define MAX_N 3000+5
#endif

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


ll dp[MAX_N][MAX_N][26+1][MAX_N];

void solve(){
  ll N, P;
  cin >> N >> P;

  dp[0][0][0] = 1;
  rep(c,26) {
    dp[1][1][c] = 1;
  }   
  

  reps(i,1,N+1) {
    //ok
    rep(j,1,MAX_N) {
      rep(c, 26) {
        if(dp[i-1][j][c] > 0) {

        }
          dp[i][j][c] = dp[i-1][j-1][c];
      }
    }
    
  }
  
  ll ans =0;

  reps(j,1,27) reps(k,1,27) {
    ans += dp[N][j][k][1];
    ans %= P;
  }
  cout << ans << endl;

}



int main(){
    solve();
    return 0;
}
