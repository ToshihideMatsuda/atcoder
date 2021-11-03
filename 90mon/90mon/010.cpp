//
//  main.cpp
//  90mon
//
//  Created by 松田敏秀 on 2021/10/12.
//
/*
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    
    int kumiSum[3][n+1];
    for (int i=1; i <= n; i++) {
        int kumi, score;
        cin >> kumi;
        cin >> score;
        if(kumi == 1) {
            kumiSum[1][i] = kumiSum[1][i-1] + score;
            kumiSum[2][i] = kumiSum[2][i-1];
        }
        else {
            kumiSum[1][i] = kumiSum[1][i-1];
            kumiSum[2][i] = kumiSum[2][i-1] + score;
        }
        
    }
    
    int q;
    cin >> q;
    
    for (int i=0; i < q; i++) {
        int l, r;
        cin >> l;
        cin >> r;
        cout << (kumiSum[1][r] - kumiSum[1][l-1]);
        cout << " " ;
        cout << (kumiSum[2][r] - kumiSum[2][l-1]);
        cout << "\n" ;
    }
    
    return 0;
}

*/
