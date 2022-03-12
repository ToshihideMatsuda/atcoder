#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
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
    #define MAX_N 2*100000 + 5
#endif

void OK() {
  cout << "Yes" << endl;
  exit(0);
}

int dp[1000000+5][10];

void solve(){
    int N;
    cin>>N;
    
    rep(i,10)dp[1][i]=1;
    reps(i,2,N+1){
    	dp[i][1]=dp[i-1][1]+dp[i-1][2];
    	dp[i][9]=dp[i-1][9]+dp[i-1][8];
    	reps(j,2,9){
    		 dp[i][j]=(dp[i-1][j]+dp[i-1][j-1])%MOD+dp[i-1][j+1];
    		 }
    	reps(j,1,10) dp[i][j] %=MOD;
    	
    }
    
    int sum =0;
    reps(i,1,10){
    	sum+=dp[N][i];
    	sum%=MOD;
    }
    cout << sum;
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



