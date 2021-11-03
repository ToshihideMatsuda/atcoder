//
//  c.cpp
//  90mon
//
//  Created by 松田敏秀 on 2021/10/23.
//
/*
#include <iostream>
#include <vector>
#include <limits>
#include <set>

using namespace std;


int main() {
    int n;
    
    cin >> n;
    
    vector<pair<int,int>> xy;

    for(int i=0; i < n; i ++) {
        int X,Y;
        cin >> X >> Y;
        xy.push_back(make_pair(X,Y));
    }
    
    int sum = 0;
    
    sort(xy.begin(),xy.end());
    
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            for(int k=j+1; k<n; k++) {
                //3点がわかっている3角形の面積は1/2|(x1 - x3)(y2 - y3) - (x2 -x3)(y1 - y3)|
                int menseki = (xy[i].first - xy[k].first)*(xy[j].second - xy[k].second) -
                              (xy[j].first - xy[k].first)*(xy[i].second - xy[k].second);
                
                if(menseki != 0){
                    sum ++;
                }
                
            }
        }
    }
    
    cout << sum;
    
    return 0;
}



*/
