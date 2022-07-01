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
    #define MAX_N 2*  100000 + 5
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


void solve(){
    ll N;
    cin >> N;

    vector<ll> T(N);
    ll sum = 0;
    rep(i,N) {
        cin >> T[i];
        sum += T[i];
    }
    ll ave = (sum+1)/2;

    bool dp[N+1][sum];
    memset(dp,0,sizeof(dp));

    dp[0][0] = true;
    reps(i,1,N+1) {
        rep(j,sum+1) {
            dp[i][j] = dp[i-1][j];
            if(j-T[i-1] >= 0) {
                dp[i][j] |= dp[i-1][j-T[i-1]];
            }
        }
    }

    reps(ans,ave,sum+1) {
        if(dp[N][ans]) {
            cout << ans << endl;
            return;
        }
    }


}



int main(){
    solve();
    return 0;
}

