#include <iostream>
#include <vector>
#include <queue>

//プリム法　重み付き連結グラフの最小全域木を求める最適化問題のアルゴリズム

using namespace std;

#define MAX_V 10000
#define INF 1 << 28;
vector<pair<int, int>> G[MAX_V+1]; // G[from] = { cost, to } 頂点 from->to の辺のコストがcost
int mincost[MAX_V+1];               // すでに確定済みの部分グラフTからの拡張点の最小コスト
int used[MAX_V+1];
int usedCnt =0;
int N;

// Gが連結なグラフの場合に動作する
int prim(int s) {
    for (int i = 1;i <= N; i++) {
        mincost[i] = INF;
        used[i] = false;
    }

    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> Q;// priority queue { c, v }

    //開始地点sから到達できる箇所のコストを登録
    for(auto pair:G[s]){
        auto v = pair.second;
        auto c = pair.first;
        Q.push({c,v});
    }

    used[s] = true;
    usedCnt ++;

    int ans = 0;
    
    while(usedCnt < N) {    //全てのVが登録されるまで実施
        //コスト最小辺を抽出
        auto pair = Q.top();Q.pop();
        auto v = pair.second;
        auto c = pair.first;

        if(!used[v]) {
            used[v] = true;
            ans += c;       //コストを追加
            usedCnt ++;
            for(auto u : G[v]) Q.push(u); //辺を追加
        }
    }
    return ans;
}

int debug() {
    N = 4;

    // 1-2 cost 6
    G[1].push_back({6,2});
    G[2].push_back({6,1});

    // 1-3 cost 3
    G[1].push_back({3,3});
    G[3].push_back({3,1});

    // 1-4 cost 1
    G[1].push_back({1,4});
    G[4].push_back({1,1});

    // 2-3 cost 2
    G[2].push_back({2,3});
    G[3].push_back({2,2});

    // 3-4 cost 5
    G[3].push_back({5,4});
    G[4].push_back({5,3});

    // 2-4 cost 1
    G[2].push_back({1,4});
    G[4].push_back({1,2});


    int res = prim(2);

    cout << res << endl;
}

int main(){
    debug();

    return 0;
}


