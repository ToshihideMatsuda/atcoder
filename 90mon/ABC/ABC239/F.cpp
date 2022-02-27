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
#define MINF -1*(1 << 28)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#if debug == true
    #define MAX_N 100 + 5
#else
    #define MAX_N 2 * 100000 + 5
#endif


int N, M;
vector<int> D;
vector<int> G[MAX_N];
vector<pair<int,int>> H;

struct UnionFindTreeWithSize {

    vector<int> tree;  // 実態
                       // 正数:子, 負数:親(値はつながることが可能な子の数)、0:未初期化
    vector<int> dep;   // unionfind木の深さ

    UnionFindTreeWithSize(int n): tree(n,0), dep(n,0){
	    for (int i = 0; i < n; i ++) {
	        insert(i);
	    }

    }

    void insert(int edge){
        tree[edge] = -D[edge];
        dep[edge] = 1;
    }

    // rootを辿って同じものかを判定
    bool same (int e1, int e2)  {
        int x = root(e1);
        int y = root(e2);

        if(x == y) return true;
        return false;
    }

    // rootを辿って、深さに応じてくっつける
    void unionTree(int e1, int e2) {
        int x = root(e1);
        int y = root(e2);

        if(x == y) return;

        if(dep[x] >= dep[y] ) {
            tree[x] += tree[y]+2; //負数の要素をプラス2してくっつける
            tree[y] = x;
            dep[y] ++;
        } else {
            tree[y] += tree[x]+2; //負数の要素をプラス2してくっつける
            tree[x] = y;
            dep[x] ++;
        }
    }

    // treeの先を辿ってtreeにする
    int root(int e) {
        int r = tree[e];
        if(r < 0 ) { return e;} //負数が親
        else {
            tree[e] = root(r);
            return tree[e];
        }
    }

    int getSize(int e) {
        int r = root(e);
        return tree[r] * -1;
    }

};


void solve(){
    cin >> N >> M;
    rep(i,N) {
        int d;
        cin >> d;
        D.push_back(d);
    }

    rep(i,M) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    //sum D_iが2*(N-1)でないならアウト
    int sumD =0;
    rep(i,N) sumD += D[i];
    if(sumD != 2*(N-1)) {
        cout << "-1" << endl;
        return;
    }

    //全ての頂点に関して、現在の頂点すうがD_iより大きいならアウト
    set<int> kouhoOver2, kouho1;
    rep(i,N) {
        if(G[i].size() > D[i]) {
            cout << "-1" << endl;
            return;
        }
        if(D[i] - G[i].size() >= 2) {
            kouhoOver2.insert(i);
        } else if(D[i] - G[i].size() >= 1) {
            kouho1.insert(i);
        }
    }

    //閉路があるとアウト
    bool checked[N];
    rep(i,N) checked[i] = false;

    queue<pair<int,int>> Q;
    UnionFindTreeWithSize uft(N); //後のために
    rep(i,N) {
        if(checked[i]) continue;
        Q.push({i, -1});
        while(Q.size() > 0) { 
            auto q = Q.front();Q.pop();
            int v = q.first;
            int from = q.second;
            if(checked[v]) {
                //閉路がある
                cout << "-1" << endl;
                return;
            }
            checked[v] = true;
            for(int u : G[v]) {
                if(from != u)
                {
                    uft.unionTree(v,u);
                    Q.push({u,v});
                }
            }
        }
    }
    

    
    //上記以外の場合構成可能？
    back:
    for(int i: kouhoOver2) {

        for(int j: kouho1) {
            if(!uft.same(i,j)) {
                uft.unionTree(i,j);
                G[i].push_back(j);
                G[j].push_back(i);
                H.push_back({i,j});
                                
                if(D[i] - G[i].size() < 2) 
                {
                    kouhoOver2.erase(i);
                    kouho1.insert(i);
                }
                if(G[j].size() == D[j]) kouho1.erase(j);
                        
                goto back;
            }
        }
    }

    kouho1.merge(kouhoOver2);

    //上記以外の場合構成可能？
    back2:
    for(int i: kouho1) {
        if(uft.getSize(i) > 1) {
            for(int j: kouho1) {
                if(!uft.same(i,j)) {
                    uft.unionTree(i,j);
                    G[i].push_back(j);
                    G[j].push_back(i);
                    H.push_back({i,j});
                        
                    if(G[i].size() == D[i]) kouho1.erase(i);
                    if(G[j].size() == D[j]) kouho1.erase(j);
                        
                    goto back2;
                }
            }
        }
    }
 
    for(int i: kouho1) {
        for(int j: kouho1) {
            if(!uft.same(i,j)) {
                uft.unionTree(i,j);
                G[i].push_back(j);
                G[j].push_back(i);
                H.push_back({i,j});
                goto next;
            }
        }
    }
    next:
    
    //全ての頂点に関して、現在の頂点すうがD_iより大きいならアウト
    rep(i,N) {
        if(G[i].size() != D[i]) {
            cout << "-1" << endl;
            return;
        }
    }

    for(auto e : H) {
        cout << e.first+1 << " " << e.second+1 << endl;
    }

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
