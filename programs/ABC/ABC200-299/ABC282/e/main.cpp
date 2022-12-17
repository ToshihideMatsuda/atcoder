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

#define MAX_N (500+5)
#define MAX_V (MAX_N*MAX_N)

vector<pair<ll, ll>> G[MAX_V+1]; // G[from] = { cost, to } 頂点 from->to の辺のコストがcost
ll used[MAX_V+1];
ll usedCnt =0;
ll N;

// Gが連結なグラフの場合に動作する
ll prim(ll s) {
    for (ll i = 1;i <= N; i++) {
        used[i] = false;
    }

    priority_queue<
        pair<ll,ll>,
        vector<pair<ll,ll>>,
        less<pair<ll,ll>>> Q;// priority queue { c, v }

    //開始地点sから到達できる箇所のコストを登録
    for(auto pair:G[s]){
        Q.push(pair);
    }

    used[s] = true;
    usedCnt ++;

    ll ans = 0;
    
    while(usedCnt < N) {    //全てのVが登録されるまで実施
        //コスト最小辺を抽出
        auto pair = Q.top();Q.pop();
        auto v = pair.second;
        auto c = pair.first;

        if(used[v] == false) {
            used[v] = true;
            ans += c;       //コストを追加
            usedCnt ++;
            for(auto u : G[v]) Q.push(u); //辺を追加
        }
    }
    return ans;
}

// 冪乗計算 (x^n) % mod の計算
// mod <= 0 の場合には通常の冪乗計算（オーバーフロー無視）
ll pow(ll x, ll n, ll mod) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1) {  // n の最下位bitが 1
            ret *=x;  // n の最下位bitが 1 ならば x^(2^i) をかける
            if(mod > 0) ret %=mod;
        }
        x *= x;       // nのビット数分だけ累乗する
        x %= mod;
        n >>= 1;      // n を1bit 左にずらして次のビットを見る
    }
    return ret ;       // ret = ( x^n )% mod 
                      //     = (x^(10110...1)_2 % mod )みたいなイメージで計算していく
}


ll f(ll x, ll y, ll M) {
  return (pow(x,y,M) + pow(y,x,M)) % M;
}

void solve() {
  ll  M; cin >> N >> M;
  vector<ll> A(N+1); rep(i,N) cin >> A[i+1];
  reps(u,1,N) reps(v,u+1,N+1){
    ll c = f(A[u], A[v], M);
    G[u].push_back({ c,v });
    G[v].push_back({ c,u });
  }
  ll ans = prim(1);
  cout << ans << endl;
  
}


int main()
{
  solve();
	return 0;
}