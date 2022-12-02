#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) max(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) min(a,MIN(b,c))

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N (100+5)

 // グラフの隣接行列
 // 配列d[a][b]には頂点a,b間の辺のコストを入れておき、a=bの時は0を、a,b間の辺が存在しないときはINFを入れておく。
 //
 // rep(i,MAX_N) rep(j,MAX_N) d[i][j] = (i == j ? 0 : INF);
 // rep(i,M){
 //   ll a, b, c;
 //   cin >> a >> b >> c;
 //   d[a][b] = c;
 //   d[b][a] = c;
 // }

set<ll> edges[MAX_N][MAX_N];
ll d[MAX_N][MAX_N];

ll N, M; 
void warshall_floyd() {
  reps(k,1,N+1) {           // 経由する頂点
      reps(i,1,N+1) {       // 始点
          reps (j,1,N+1) {  // 終点
          if(i == 2 && j == 3 && k == 1) {
            ll a = 0;
          }
          if( d[i][k] + d[k][j] < d[i][j] ) {
              d[i][j] = d[i][k] + d[k][j];
              set<ll> newEdge;
              for(auto e: edges[i][k]) {
                newEdge.insert(e);
              }

              for(auto e: edges[k][j]) {
                newEdge.insert(e);
              }
              
              edges[i][j] = newEdge;

          } else if(d[i][k] + d[k][j] == d[i][j]) {

               for(auto e: edges[i][k]) {
                edges[i][j].insert(e);
              }

               for(auto e: edges[k][j]) {
                edges[i][j].insert(e);
              }
          }
          }
      }
    }
}

void solve() {cin >> N >> M;
  reps(i,1,N+1) reps(j,1,N+1) {
     d[i][j] = (i == j ? 0 : INF_LL);
  }
  
  rep(i,M){
    ll a, b, c;
    cin >> a >> b >> c;
    d[a][b] = c;
    d[b][a] = c;
    
    edges[a][b].insert(i+1);
    edges[b][a].insert(i+1);
  }
  warshall_floyd();

  set<ll> allEdge;
  reps(i,1,N+1) reps(j,1,N+1) for(auto e : edges[i][j]) allEdge.insert(e);
  cout << M - allEdge.size() << endl;
}


int main()
{
  solve();
	return 0;
}