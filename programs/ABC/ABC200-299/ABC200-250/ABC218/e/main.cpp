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


vector<tuple<ll, ll, ll>> G[MAX_N];
bool used[MAX_N];
ll all[MAX_N];
ll usedCnt =0;
ll N, M;;

// Gが連結なグラフの場合に動作する
set<ll> prim(ll s, bool min) {
    rep(i,MAX_N) used[i] = false;

    priority_queue Q = priority_queue<
        tuple<ll,ll,ll>,
        vector<tuple<ll,ll,ll>>,
        greater<tuple<ll,ll,ll>> >(); // priority queue { c, v }

    //開始地点sから到達できる箇所のコストを登録
    for(auto pair:G[s]){
        Q.push(pair);
    }

    used[s] = true;
    usedCnt ++;

    set<ll> ans;

    
    while(usedCnt < N) {    //全てのVが登録されるまで実施
        //コスト最小辺を抽出
        ll v,c,i;
        tie(c,v,i) = Q.top();Q.pop();

        if(used[v] == false) {
            used[v] = true;
            ans.insert(i);       //辺を追加
            usedCnt ++;
            for(auto u : G[v]) Q.push(u); //辺を追加
        }
    }
    return ans;
}

void solve() {
  cin >> N >> M;

  vector<ll> cost(MAX_N);

  reps(i,1,1+M) {
    ll a, b, c;
    cin >> a >> b >> c;
    G[a].push_back({c,b,i});
    G[b].push_back({c,a,i});
    cost[i] = c;
  }

  set<ll> used = prim(1,true);

  ll ans = 0;
  reps(i,1,1+M) {
    if(cost[i] > 0 && !used.count(i)) {
      ans += cost[i];
    }
  }

  cout << (ans) << endl;

}


int main()
{
  solve();
	return 0;
}