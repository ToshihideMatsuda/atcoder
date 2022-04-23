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
#include <bits/stdc++.h> 

using namespace std;

#define debug false

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 



#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#if debug == true
    #define MAX_N 100 + 5
#else
    #define MAX_N 10000 + 5
#endif

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}
void UNSOLVABLE() {
  cout << "UNSOLVABLE" << endl;
}


/*
    以下のロジックでグラフGに頂点aから頂点bへのコストcを入れておく
    rep(i,M){
        ll a, b, c;
        cin >> a >> b >> c;
        G.push_back({a,b,c});
        G.push_back({b,a,c});
    }
*/
vector<tuple<ll,ll,ll>> G; // G = [{from, to, cost}];

ll N, M; // 頂点数, 辺の数


ll d[MAX_N]; // distance（最終的な出力）
// 戻り値が true -> 負の閉路がある
bool bellmanford(ll start) {

    rep(i,MAX_N) d[i] = INF_LL;
    d[start] = 0;

    ll from, to, cost;
    rep (cnt, N) {
        for (auto g : G) {
            tie(from, to, cost) = g;

            if (d[from] != INF_LL && d[from] + cost < d[to]) {
                if(cnt == N-1) return true; //頂点数に達していれば負閉路がある
                d[to] = d[from] + cost;
            }
        }
    }
    //負閉路がなし
    return false;
}


void solve(){
    cin >> N >> M;

    rep(i,M){
        ll a, b, c;
        cin >> a >> b >> c;
        G.push_back({a,b,c * -1});
    }
    bool ret = bellmanford(1);
    if(ret) {
        cout << "inf" << endl;
        return;
    }

    cout << -1LL*d[N] << endl;

}


int main(){
    solve();
    return 0;
}

