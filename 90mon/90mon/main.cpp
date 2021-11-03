#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 無向重みつきグラフ G[i] = (c,j) i -> jへの」移動の際にかかるコストc
vector<pair<int,int>> G[nmax];
int INF = 1 << 28;

// startから移動する際の累計コスト
int cost[nmax];                 

void dikstra(int start) {

    //costには限界近い大きい値を入れておく
    for (int i = 1; i < n+1; i ++) cost[i] = ;

    //コストが最小の点を探すため、priorityQueue
    priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int, int>>> Q;
    
    Q.push(pair(0,start));
    cost[start]=0;
    
    while(Q.size() > 0) {

        auto from = Q.top();Q.pop();
        auto to = G[from.second];
        for(int i = 0; i < to.size(); i++){
            int currentCost = cost[to[i].second];
            int otherCost   = to[i].first + from.first;

            //今のコストよりも良い場合には、cost配列を更新して、Queue に登録            
            if(currentCost > otherCost){
                cost[to[i].second] = otherCost;
                Q.push(pair(otherCost,to[i].second));
            }
        }
        
    }

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


