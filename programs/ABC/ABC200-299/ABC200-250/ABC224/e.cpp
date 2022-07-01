//
//  main.cpp
//  90mon
//
//  Created by 松田敏秀 on 2021/10/12.
//
#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <map>
#include <regex>

using namespace std;

int h,w,n;

int dp[2*100000 + 1]; // iが移動できる数 max dp
int rmax[2*100000 + 1],cmax[2*100000 + 1];  // rmax:行最大値dp、cmax:列最大値dp
int r[2*100000 +1],c[2*100000 +1],a[2*100000 +1];
map<int,vector<int>> AtoIs;

int main() {
    
    cin >> h >> w >> n;

    for(int i=1; i < n+1; i ++) {
        cin >> r[i] >> c[i] >> a[i];
        AtoIs[a[i]].push_back(i);
    }

#if debug
    cout << "----" << endl;
    for(auto it = AtoIs.rbegin(); it !=AtoIs.rend();it++ ) { 

        cout << "map[" + to_string(it->first) + "]=";
        for(auto i : it->second) {
            cout << i << ",";
        }
        cout << endl;
    }
    cout << "----" << endl;
#endif

    // map に関してはキー項目にて大きい方から並んでいる
    for(auto it = AtoIs.rbegin(); it !=AtoIs.rend();it++ ) { 
        for(auto i : it->second){
            dp[i] = max(rmax[r[i]],cmax[c[i]]);
        }

        for(auto i : it->second) {
            rmax[r[i]] = max(rmax[r[i]], dp[i] + 1);
            cmax[c[i]] = max(cmax[c[i]], dp[i] + 1);
        }
    }

    for(int i = 1; i < n+1;i++) {
       cout << dp[i] << endl;
    }
    
    return 0;
}
