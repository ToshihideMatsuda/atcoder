//
//  main.cpp
//  90mon
//
//  Created by 松田敏秀 on 2021/10/12.
//
/*
#include <iostream>
#include <queue>
#include <climits>
#include <vector>

using namespace std;
#define nmax 200 * 2 + 9

int dp[nmax][nmax];
int a [nmax];

int main(){
    int n;
    
    std::cin >> n;
    
    
    for(int i = 0; i <2*n; i++){
        std::cin >> a[i];
    }
    
    for(int i = 0; i <2*n; i++){
        for(int j = 0; j <2*n; j++){
            dp[i][j]= 1 << 29;
        }
    }
    
    queue<pair<int,int>>Q;
    for(int i = 0; i <2*n-1; i++){
       int d =a[i] -a[i+1];
        dp[i][i+1]= d >0 ? d :-1*d;
        Q.push(pair(i,i+1));
    }
    
    while(Q.size()>0){
        auto q=Q.front();Q.pop();
        int f = q.first;
        int s = q.second;
        if(f==0){
            if(s>=2*n-1){
                //増やさない
            }
            else {
                Q.push(pair(0,s+2));
            }
        }
        else if(s==2*n-1){
            Q.push(pair(f-2,s));
        }
        else{
            Q.push(pair(f-1,s+1));
        }
        
        if(f + 1 == s) continue;
        
        int df = abs(a[f] - a[s]);
        dp[f][s] = min(dp[f][s], dp[f+1][s-1] + df);
        for(int i = 1; f + i < s; i++) {
            dp[f][s] = min(dp[f][s], dp[f][f+i] + dp[f+(i+1)][s] );
        }
    }
    
    std::cout << dp[0][2*n - 1];
    
    return 0;
}
*/
