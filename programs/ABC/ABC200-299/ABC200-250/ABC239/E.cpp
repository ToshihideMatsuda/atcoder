#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <numeric>

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
    #define MAX_N 100000 + 5
#endif


int N, Q;
vector<int> G[MAX_N];
vector<int> X;
vector<vector<int>> K;

void computeK(int v, int from) {

    if(G[v].size() == 1) {
        if(G[v][0] == from) {
            //葉ノード
            if(debug) {
                cout << "葉ノード:" << (v+1) << endl;
            }
            K[v].push_back(X[v]);
            return;
        }
    }

    //計算
    vector<int> tmp;
    tmp.push_back(X[v]);
    for(int u:G[v]) {
        if(u == from) continue; //親ノードは除外
        if(K[u].size() == 0) {
            computeK(u, v);
        }
        tmp.insert(tmp.begin(), K[u].begin(), K[u].end());
    }
    //葉ノード
    int size = tmp.size();
    if(debug) {
        cout << "枝ノード（マージ前）:" << (v+1) << endl;
        rep(i,size) cout << tmp[i] << " ";
        cout << endl;
    }

    sort(tmp.begin(), tmp.end(),greater<int>());
    tmp.resize(20);
    K[v] = tmp;

    if(debug) {
        cout << "枝ノード（マージ後）:" << (v+1) << endl;
        size = K[v].size();
        rep(i,size) cout <<K[v][i] << " ";
        cout << endl;
    }
}

void solve(){
    cin >> N >> Q;
    X = vector<int>(N);
    K = vector<vector<int>>(N);
    rep(i, MAX_N) G[i] = vector<int>();

    rep(i,N) cin >> X[i];

    rep(_, N-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    } 

    computeK(0, -1);

    rep(_, Q) {
        int v, k;
        cin >> v >> k;
        v--;k--;
        cout << K[v][k] << endl;
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
