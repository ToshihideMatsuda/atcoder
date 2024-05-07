#include <bits/stdc++.h> 
#define rep(i,n)     for(ll i = 0; i < n; i++ ) 

//クラスカル法　重み付き連結グラフの最小全域木を求める最適化問題のアルゴリズム
//辺のコスト順にソートし、その順にUnionFindTreeにて連結していない頂点を追加して、最小全域木を求める
typedef long long ll;
using namespace std;

#define MAX_N (2*100000)

vector<pair<ll, ll>> G[MAX_N]; // G[from] = { cost, to } 頂点 from->to の辺のコストがcost
bool used[MAX_N];
ll usedCnt =0;
ll N, M;


template<typename T>
struct UnionFindTree {

    unordered_map <T,T> tree;  // T -> TのUnionTreeの実態
    unordered_map <T,int>dep; // unionfind木の深さ

    UnionFindTree() {}

    void insert(T edge){
        tree[edge] = edge;
        dep[edge] = 1;
    }
    
    bool exist(T edge){
        return tree.count(edge) > 0;
    }

    // rootを辿って同じものかを判定
    bool same (T e1, T e2)  {
        T x = root(e1);
        T y = root(e2);

        if(x== y) return true;
        return false;
    }

    // rootを辿って、深さに応じてくっつける
    void unionTree(T e1, T e2) {
        T x = root(e1);
        T y = root(e2);

        if(x== y) return;

        if(dep[x] >= dep[y] ) {
            tree[y] = x;
            dep[y] ++;
        } else {
            tree[x] = y;
            dep[x] ++;
        }
    }

    // treeの先を辿ってtreeにする
    T root(T e) {
        T r = tree[e];
        if(r == e) { return r;}
        else {
            tree[e] = root(r);
            return tree[e];
        }
    }

};


//クラスカル法 入力N: 1...Nを頂点とするグラフGが対象
ll kruskal(int N) {
    vector<tuple<ll, int, int>> edges; // (cost,from,to)
    for (int i = 1; i <= N; i++) {
        for (auto &e : G[i]) {
            int to = e.second;
            ll cost = e.first;
            if (i < to) { // 重複を避けるために一方向のみをリストに追加
                edges.emplace_back(cost, i, to);
            }
        }
    }

    UnionFindTree<ll> uft;
	for(int i = 1; i <= N; i ++) uft.insert(i);
	
    
    sort(edges.begin(), edges.end()); // コストでソート
    ll total_cost = 0;

    //コスト順に辺を追加していく。unionfind木ですでに連結済みの辺はスキップ
    for (auto &e : edges) {
        auto [cost, u, v] = e;
        if (!uft.same(u, v)) {
            uft.unionTree(u, v);
            total_cost += cost;
        }
    }
    return total_cost;
}
