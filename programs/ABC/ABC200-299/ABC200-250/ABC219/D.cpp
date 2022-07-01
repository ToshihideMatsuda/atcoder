#include <iostream>

using namespace std;

#define max 300 + 1
int N, X, Y;
int A[max], B[max];
int dp[max][max][max];
int INF = 1 << 28;
/* 
 dp[i][j][k]=l : i番目まで見終わって選択する弁当の数がl個、その時のたこ焼きがj個でたい焼きがk個
 初期値 dp[0][0][0] = 0 otherwise dp[i][k][l] = INF
 終値 　dp[N][X][Y]
 遷移   1 <= i <= Nに対して、jとkの範囲を 0 <= j <= X + A[i], 0 <= k <= Y+B[i]として
       dp[i][min(j,X)][min(k,Y)]= min(dp[i] [min(j,X)][min(k,Y)],　 //j,kがX,Yを超えた場合にX,Yに収束
                                　min(dp[i-1][min(j,X)][min(k,Y)],  //i番目を選ばない場合
                                    　dp[i-1][j-A[i]][k-B[i]]+1));  //i番目を選ぶ場合
*/
//---------------------------------------------------------------------------------------------------
int main() {
    cin >> N >> X >> Y;

    for(int i = 1; i <= N ; i++) cin >> A[i] >> B[i];
    
    for(int i = 0; i < max; i ++) {
        for(int j = 0; j < max; j++) {
            for(int k = 0; k < max; k++) {
                dp[i][j][k] = INF;
            }
        }
    }

    dp[0][0][0] = 0;

    for(int i = 1; i <= N; i ++) {
        for(int j = 0; j <= X+A[i]; j ++) {
            for(int k = 0; k <= Y+B[i]; k ++) {
                if(j-A[i] >= 0 && k-B[i] >= 0) {
                    dp[i][min(j,X)][min(k,Y)]= min(dp[i]  [min(j,X)][min(k,Y)],
                                               min(dp[i-1][min(j,X)][min(k,Y)], 
                                                   dp[i-1][j-A[i]]  [k-B[i]]    +1));
                } 
                else
                {
                    if(j > X || k > Y)
                        continue;
                    dp[i][j][k] = dp[i-1][j][k] ;
                }
            }
        }
    }

    if(dp[N][X][Y]== INF) cout << -1 << endl;
    else cout << dp[N][X][Y] << endl;

    return 0;
}