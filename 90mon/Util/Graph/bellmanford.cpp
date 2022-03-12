// ベルマンフォード
// とある頂点からグラフ上の他の点への最短経路を探す、計算量はO(M*N) （Mは辺の数、Nは頂点数）
// N = 10^4ぐらい

#define INF 1 << 30
#define MAX_N 10000 + 5
typedef long long ll;
#define rep(i,n)     for(ll i = 0; i < n; i++ ) 

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

    rep(i,MAX_N) d[i] = INF;
    d[start] = 0;

    ll from, to, cost;
    rep (cnt, N) {
        for (auto g : G) {
            tie(from, to, cost) = g;

            if (d[from] != INF && d[from] + cost < d[to]) {
                if(cnt == N-1) return true; //頂点数に達していれば負閉路がある
                d[to] = d[from] + cost;
            }
        }
    }
    //負閉路がなし
    return false;
}