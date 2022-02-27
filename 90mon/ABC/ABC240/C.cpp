#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <numeric>

using namespace std;

#define debug false

#define rep(i,n)     for(int i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(int i = m; i < n; i++ ) 


typedef long long ll;

#define INF 1 << 28
#define MINF -1*(1 << 28)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#if debug == true
    #define MAX_N 100 + 5
#else
    #define MAX_N 100000 + 5
#endif

int N, X;

bool dp[100+5][MAX_N];

void solve(){
    cin >> N >> X;

    rep(i,100+5) rep(j,MAX_N) dp[i][j] = false;
    dp[0][0] = true;
    

    reps(i,1,N+1) {
        int a, b;
        cin >> a >> b;
        rep(j, MAX_N) {
            if(j-a >= 0 && j-b >= 0) {
                if(dp[i-1][j-a] || dp[i-1][j-b]) dp[i][j] = true;
            } else if(j-a >= 0) { 
                if(dp[i-1][j-a]) dp[i][j] = true;
            } else if(j-b >= 0) {
                if(dp[i-1][j-b]) dp[i][j] = true;
            }
        }
    }


    if(dp[N][X]) cout << "Yes" << endl;
    else cout << "No" << endl;
}


int main(){

#if debug == true
    while(true){
        cout << "---debugMode---" << endl;
#endif
        solve();
        cout << endl;
#if debug == true
    }
#endif

    return 0;
}
