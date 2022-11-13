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

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N*2];
ll cost[MAX_N*2];

//01BFSによる解法
void solve() {
  ll N, M, K; cin >> N >> M >> K;
  rep(i,M) {
    ll u, v, a;
    cin >> u >> v >> a;
    if(a == 1) {
      // a == 1の場合、u <-> v に辺を張る
      G[u].push_back(v);
      G[v].push_back(u);
    } else {
      // a == 0の場合、N+u <-> N+v に辺を張る
      G[N+u].push_back(N+v);
      G[N+v].push_back(N+u);
    }
  }

  //スイッチがsある場合、Sにs,N+s登録しておき、s <-> N+sに辺を張る
  rep(i,K) {
    ll s;
    cin >> s;
    G[s].push_back(N+s);
    G[N+s].push_back(s);
  }

  //01BSFのため両端キューを準備。
  //最短距離ノードが順に入っている。
  //遷移に重さ0の辺を使用した場合には先頭に登録、重さ１の辺を登録した場合には最後に登録
  deque<ll> DQ;
  DQ.push_back(1); 

  rep(i,MAX_N*2)cost[i] = INF_LL;
  cost[1] = 0;
  
  while(DQ.size() > 0) {
    ll p;
    p = DQ.front(); DQ.pop_front();
    for(auto g : G[p]) {
      if(MIN(g,p)+N == MAX(g,p)) { //重さ0のノード（スイッチ）
        if(cost[p] < cost[g]) {
          cost[g] = cost[p];
          DQ.push_front(g);
        }
      } else {
        if(cost[p]+1 < cost[g]) {
          cost[g] = cost[p]+1;
          DQ.push_back(g);
        }
      }
    }
  }

  //a==1でたどり着いた最小コストcost[N]、a==0でたどり着いた最小コストcost[2*N]
  ll ans = MIN(cost[N], cost[2*N]);
  if(ans == INF_LL) {
    cout << -1 << endl;
  } else {
    cout << ans << endl;
  }


}


int main()
{
  solve();
	return 0;
}