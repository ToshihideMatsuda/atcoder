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


vector<int> G[9+1];
int m;
map<string,int> mp;

int main() {

    std::cin >> m;

    for(int i=0; i < m; i ++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    
    string komaposition = "999999999";
    for(int i=1; i < 9; i ++) {
        int pt;
        cin >> pt;
        komaposition[pt-1] = i + '0';
    }
    mp[komaposition]=0;

    queue<string> Q;

    Q.push(komaposition);

    while(Q.size() >0) {
        string current = Q.front();Q.pop();
        
        int v = 0;
        for(int i = 0; i < 9; i ++) if(current[i] == '9') v = i;

        for(int u : G[v+1]) {
            string nxt(current);
            swap(nxt[v], nxt[u-1]);
        
            if(mp.count(nxt)){continue;}
            mp[nxt]= mp[current] +1;
            Q.push(nxt);
        }
    }


    if(mp.count("123456789")) cout << mp["123456789"];
    else cout << -1 << endl;
    
    return 0;
}
