//
//  main.cpp
//  90mon
//
//  Created by 松田敏秀 on 2021/10/12.
//

#include <iostream>

using namespace std;

// Input
int N;
int lx[1 << 18], ly[1 << 18], rx[1 << 18], ry[1 << 18];
int M[1000+9][1000+9];
int cnt[1 << 18];

int main() {
    
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> lx[i] >> ly[i] >> rx[i] >> ry[i];
        M[lx[i]][ly[i]] +=1;
        M[rx[i]][ry[i]] +=1;
        M[lx[i]][ry[i]] -=1;
        M[rx[i]][ly[i]] -=1;
    }
    
    for(int i = 0; i < 1000 + 9; i++) {
        for(int j = 1; j < 1000 + 9; j++) {
            M[i][j] += M[i][j-1];
        }
    }
 
    for(int i = 1; i < 1000+9; i++) {
        for(int j = 0; j < 1000+9; j++) {
            M[i][j] += M[i-1][j];
        }
    }
    
    

    for(int i = 0; i < 1000+9; i++) {
        for(int j = 0; j < 1000+9; j++) {
            cnt[M[i][j]]++;
        }
    }

 
    
    for(int i= 1; i<N+1;i++){
        cout << cnt[i] << endl;
    }

    return 0;
}


