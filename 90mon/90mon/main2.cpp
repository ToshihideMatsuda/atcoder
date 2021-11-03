#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N,K;
    cin >> N >> K;
    string s[N+1];
    for(int i=1; i<N+1; i++) cin >> s[i];
    
    while(true){
        bool swaped = false;
        for(int i=1;i < N;i++){
            if(!(s[i] + s[i+1] <= s[i+1] +s[i])) {
                swap(s[i],s[i+1]);
                swaped = true;
                break;
            }
        }
        if(!swaped)
            break;
    }
    
    string dp[N+2][K+1];
    string inf = "~" ;
    for(int i = 0; i < N+2; i ++) {
        for(int k = 0; k < K+1;k++) {
            dp[i][k] = inf;
        }
    }
    for(int i = N; i > 0; i--) {
        for(int k = 1; k <= K ; k++) {
            dp[i][k] =
            min(
                dp[i+1][k],
                s[i]+(dp[i+1][k-1] == inf ? "" : dp[i+1][k-1] )//
            );
        }
    }
    cout << dp[1][K] << endl;
    return 1;
}
