
// ダイクストラ法
// とある頂点からグラフ上の他の点への最短経路を探す、計算量はO(M*log(N)) （Mは辺の数、Nは頂点数）
// 負経路はダメなのでベルマンフォード法を使う
// N = 2*10^5ぐらい


typedef long long ll;
#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define INF 1 << 30
#define MAX_N 2*100000 + 5

/*
    以下のロジックでグラフGに頂点aから頂点bへのコストcを入れておく
    rep(i,M){
        ll a, b, c;
        cin >> a >> b >> c;
        G[a].push_back({c,b});
        G[b].push_back({c,a});
    }
*/
 // G[from]= {cost, to}
vector<pair<ll,ll>> G[MAX_N];


ll cost[MAX_N]; // cost

void dijkstra(ll start) {
    reps(i,1,N+1) cost[i] = INF;

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>,greater<pair<ll, ll>>> Q;
    
    Q.push(pair(0,start));
    cost[start]=0;
    
    while(Q.size() > 0) {
        auto from = Q.top();Q.pop();
        auto to = G[from.second];
        rep(i,to.size()){
            ll current = cost[to[i].second];
            ll better = to[i].first + from.first;
            if(current > better){ //より良い経路発見
                cost[to[i].second] = better;
                Q.push(pair(better,to[i].second));
            }
        }
        
    }

}
