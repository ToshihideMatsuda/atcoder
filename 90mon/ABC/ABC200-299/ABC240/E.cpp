#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
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
    #define MAX_N 2*100000 + 5
#endif

vector<int> G[MAX_N];
pair<int,int> ans[MAX_N];
int cur = 1;

void computeAns(int v, int from) {
    if(G[v].size() == 1 && G[v][0] == from) {
        ans[v] = {cur, cur};
        cur ++;
        return;
    }

    int l = INF;
    int r = -1;

    for(auto u : G[v]) {
        if(u == from) continue;
        computeAns(u, v);
        l = min(l, ans[u].first);
        r = max(r, ans[u].second);
    }
    ans[v] = {l,r};
}

void solve(){
    int N;
    cin >> N;
    rep(i,N-1) {
        int a,b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    computeAns(1,-1);

    reps(i,1, N+1) {
        cout << ans[i].first << " " << ans[i].second << endl;
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
