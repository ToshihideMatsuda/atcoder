//
//  b.cpp
//  90mon
//
//  Created by 松田敏秀 on 2021/10/23.
//
/*

#include <iostream>
#include <vector>
#include <limits>

using namespace std;

int main() {
    int h, w;
    
    cin >> h >> w;
    
    int a[h+1][w+1];

    for(int i=1; i < h+1; i ++) {
        for(int j = 1; j < w+1; j++) {
            cin >> a[i][j];
        }
    }
    
    bool ok = true;
    for(int i1=1; i1<h+1; i1 ++) {
        for(int i2=i1+1; i2<h+1; i2++) {
            
            for(int j1=1; j1 < w+1; j1 ++) {
                for(int j2=j1+1; j2 < w+1; j2++) {
                    if(! (a[i1][j1] + a[i2][j2] <= a[i1][j2] + a[i2][j1]) ) {
                        ok = false;
                        break;
                    }
                }
            }
            
        }
    }
    
    if(ok)
        cout << "Yes";
    else
        cout << "No";
    
    
    return 0;
}

*/
