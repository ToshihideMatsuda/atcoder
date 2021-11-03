//
//  main.cpp
//  90mon
//
//  Created by 松田敏秀 on 2021/10/12.
//

/*
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define nmax 100009
int n,m;
vector<pair<int,int>> G[nmax];
int A[nmax],B[nmax],C[nmax];
int cost[nmax];

void dikstra(int start);

int main(){
    std::cin >> n >> m;

    for (int i = 0; i < m; i ++) {
        std::cin >> A[i] >> B[i] >> C[i];
        G[A[i]].push_back(pair(C[i],B[i]));
        G[B[i]].push_back(pair(C[i],A[i]));
    }
    
    dikstra(1);
    int cost0[nmax];
    for (int i = 1; i < n+1; i ++) cost0[i] = cost[i];
    
    
    dikstra(n);
    
    for (int i = 1; i < n+1; i ++) {
        std::cout << (cost0[i] + cost[i]) << std::endl;
    }

    return 0;
}

void dikstra(int start) {
    for (int i = 1; i < n+1; i ++) cost[i] = INT_MAX;

    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int, int>>> Q;
    
    Q.push(pair(0,start));
    cost[start]=0;
    
    while(Q.size() > 0) {
        auto from = Q.top();Q.pop();
        auto to = G[from.second];
        for(int i = 0; i < to.size(); i++){
            int current = cost[to[i].second];
            int better = to[i].first + from.first;
            if(current > better){
                cost[to[i].second] = better;
                Q.push(pair(better,to[i].second));
            }
        }
        
    }

}
*/
