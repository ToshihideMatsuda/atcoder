#include <bits/stdc++.h> 
#include <unordered_map> 

// ダイクストラ法
// とある頂点からグラフ上の他の点への最短経路を探す、計算量はO(M*log(N)) （Mは辺の数、Nは頂点数）
// 負経路はダメなのでベルマンフォード法を使う
// N = 2*10^5ぐらい

using namespace std;
typedef long long ll;
#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define INF 1 << 30
#define INF_LL 1LL << 60
#define MAX_N 2*100000 + 5

// G[from]= {cost, to}
vector<pair<ll,ll> > G [MAX_N];
ll cost[MAX_N];

void dijkstra(ll start){
  ll N, M;
  cin >> N >> M;
  rep(i,M) {
      //以下のロジックでグラフGに頂点aから頂点bへのコストcを入れておく
      ll a, b, c;
      cin >> a >> b >> c;
      G[b].push_back(make_pair(c,a));
      G[a].push_back(make_pair(c,b));
  }
  
  priority_queue<pair<ll,ll>, vector<pair<ll, ll> >, greater<pair<ll,ll> > > Q;

  Q.push(make_pair(0,start));

  rep(i, MAX_N) cost[i] = INF_LL;
  cost[start] = 0;

  while(Q.size() > 0) {
      auto from = Q.top();Q.pop();
      ll p = from.second;
      ll fromC = from.first;

      if(fromC != cost[p]) continue;
      
      for(auto to : G[p]) {
          ll q = to.second, toC = to.first;

          
          if(fromC + toC < cost[q]) {
              cost[q] = fromC + toC;
              Q.push(make_pair(cost[q] ,q));
          }
      }
  }

}


/* //old
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

        if(from.first != cost[from.second]) continue; //更新によって最小値では無くなったものは無視

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
*/
