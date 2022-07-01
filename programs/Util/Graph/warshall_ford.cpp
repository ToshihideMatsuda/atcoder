
// ワーシャルフロイド法
// グラフ上の全ての頂点間の最短経路を探すので計算量はO(N^3) （Nは頂点数）
// N = 100ぐらい

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define INF 1 << 30
#define MAX_N 300 + 5

ll N, M;//N頂点 M辺

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

ll d[MAX_N][MAX_N];


void warshall_floyd() {
  reps(k,1,N+1) {           // 経由する頂点
      reps(i,1,N+1) {       // 始点
          reps (j,1,N+1) {  // 終点
              d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
          }
      }
    }
}