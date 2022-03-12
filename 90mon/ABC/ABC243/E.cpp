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
    #define MAX_N 300 + 5
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


int N, M;
ll d[MAX_N][MAX_N];
vector<tuple<int,int,int>> G;


void warshall_floyd() {
  reps(k,1,N+1) {           // 経由する頂点
      reps(i,1,N+1) {       // 始点
          reps (j,1,N+1) {  // 終点
              d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
          }
      }
    }
}


void solve(){
    cin >> N >> M;

    rep(i,MAX_N) rep(j,MAX_N) d[i][j] = (i == j ? 0 : INF);
    rep(i,M){
        int a, b, c;
        cin >> a >> b >> c;
        d[a][b] = c;
        d[b][a] = c;

        G.push_back({a,b,c});
    }
    warshall_floyd();

    int a, b, c;
    int del = 0;

    for(auto g : G){
        tie(a,b,c) = g;
        reps(i,1,N+1) {
            if(i != a && i != b){
                if(d[a][i] + d[i][b] <= c){
                    del++; //もっと短い経路あり
                    break;
                }
            }
        }
    }

    cout << del << endl;    

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


