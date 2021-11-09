#include <iostream>
#include <limits>
#include <unordered_map>
#include <vector>
using namespace std;

#define MAX_N  2*100000 + 10
int N, M;
int a[100000 +1], b[100000 +1];

int G[100000 +1];

int main(){
    cin >> N >> M;
    
    int B[N+1][M+1];

    for( int i = 1; i <= N; i ++) {
        for( int j = 1; j <= M; j ++) {
            cin >> B[i][j];
        }
    }

    
    if(N == 1 && M == 1) {
        cout << "Yes";
        return 0;
    }
    
    int r =B[1][1] % 7;
    if(r==0) r= 7;
    if(M > 7-r +1) {
        cout << "No";
        return 0;
    }
    
    
    if(M == 1) {
        for( int i = 1; i < N; i ++) {
            if(B[i+1][1] - B[i][1] != 7) {
                cout << "No";
                return 0;
            }
        }
    }
    
    
    
        
    
    //行方向チェック
    for( int j = 1; j < M; j ++) {
        if(B[1][j+1] - B[1][j] != 1) {
            cout << "No";
            return 0;
        }
    }
    
    //列チェック
    for( int i = 1; i < N; i ++) {
        for( int j = 1; j < M; j ++) {
            if(B[i+1][j] - B[i][j] != 7) {
                cout << "No";
                return 0;
            }
        }
    }

    cout << "Yes";

    return 0;
}
