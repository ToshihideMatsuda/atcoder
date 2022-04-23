#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>

using namespace std;

#define debug false

#define rep(i,n)     for(int i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(int i = m; i < n; i++ ) 


typedef long long ll;

#define INF 1 << 28

#if debug == true
    #define MAX_N 10 + 5
#else
    #define MAX_N 2 * 100000 + 5
#endif

int N, M;
vector<int> H;
vector<int> G[MAX_N];
vector<pair<int,int>> G1[MAX_N];

int happy[MAX_N];
bool checked[MAX_N];

void solve1(){
    cin >> N >> M;

    H.resize(N);
    

    rep(i,N) cin >> H[i];
    rep(i,N) G[i].clear(); 
    rep(i,M) {
        int u, v;
        cin >> u >> v;
        v--;
        u--;

        G[u].push_back(v);
        G[v].push_back(u);
    }

    int l =0; //lowest
    rep(i,N) if(H[i] < H[l])  l = i;
    rep(i,N) checked[i] = false;
    rep(i,N) happy[i]   = 0;


    // variate dikstra
    // Q.push({H[u],u}) : 地点uで取得可能な最高ポイントp
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;

    // lowest point では取得可能な最高ポイントは0ポイント（どこにもいかない）
    Q.push({H[l],l}); 
    

    while(Q.size() > 0) {
        int _,u;
        tie(_,u) = Q.top();Q.pop(); 

        for(int v : G[u]) {
            
            if(H[v] == H[u]) { // v -> u　が同じ高さ
                if(happy[v] < happy[u]) {
                    happy[v] = happy[u];
                    Q.push({H[v],v});
                    checked[v] = true;
                }
            } else if (H[v] < H[u]) { // v -> u　: hike up
                if (happy[v] < happy[u] + 2*(H[v] - H[u])) {
                    happy[v] = happy[u] + 2*(H[v] - H[u]);
                    Q.push({H[v],v});
                    checked[v] = true;
                }
            } else if (H[u] < H[v]) { // v -> u　: skii
                if (happy[v] < happy[u] + (H[v] - H[u])) {
                    happy[v] = happy[u] + (H[v] - H[u]);
                    Q.push({H[v],v});
                    checked[v] = true;
                }
            }
            
            //全ての点に対して、必ず一度は訪れるように計算する
            if(checked[v] == false) {
                Q.push({H[v],v});
                checked[v] = true;
            }
        }
    }
    cout << happy[0] << endl;
}

int cost[MAX_N];

void solve(){
    cin >> N >> M;

    H.resize(N);

    rep(i,N) cin >> H[i];
    rep(i,N) G[i].clear(); 
    rep(i,N) cost[i] = INF;
    rep(i,M) {
        int u, v;
        cin >> u >> v;
        v--;
        u--;

        if(H[u] >= H[v]) 
        {
            G1[u].push_back({0  ,v});
            G1[v].push_back({H[u]-H[v],u});
        }
        else {
            G1[u].push_back({H[v]-H[u],v});
            G1[v].push_back({0  ,u});
        }
    }

    // variate dikstra
    // Q.push({c,u}) : 地点uでのコストc
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> Q;
    Q.push({0,0});
    cost[0] = 0;

    
    while(Q.size() > 0) {
        int c, u;
        tie(c,u) = Q.top();Q.pop();

        for(auto v : G1[u]) {
            int nc = c + v.first;
            if(cost[v.second] > nc) {
                cost[v.second] = nc;
                Q.push({nc,v.second});
            }
        }

    }

    int maxpos = 0;
    rep(i,N)  maxpos = max(maxpos,(H[0]-H[i]) - cost[i]);

    cout << maxpos << endl;    

}

int main(){

#if debug == true
    while(true){
        cout << "---debugMode---" << endl;
#endif
        solve();
        cout << endl;
#if debug == true
    }
#endif

    return 0;
}
