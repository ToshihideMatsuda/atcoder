#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) MIN(a,MIN(b,c))
#define out(s) cout << s << endl;
#define out2(s) cout << s;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N (2*100000+5)
//トポロジカルソート(topologicalsort)
vector<ll> G[MAX_N];
//次数 deg
vector<ll> deg;
bool ck[MAX_N]; 
ll order[MAX_N];

void clear() { rep(i,MAX_N) ck[i] = false; }


void solve() {
  ll N, M; cin >> N >> M;

  deg.resize(N+5);

  //重複除去
  set<pair<ll,ll>> s;
  rep(i,M) { 
    ll a, b; cin >> a >> b; 
    s.insert({a,b});
  }

  //有向グラフと、次数（入）を計算
  for(auto c : s) {
    ll a, b; tie(a,b) = c;
    G[b].push_back(a);
    deg[a]++;
  } 


  //次数0のノードを取得（一意のトポロジカルソートのため、複数あった場合にはエラー。通常はOK）
  ll r = 0;
  reps(i,1,N+1) {
    if(deg[i] == 0) {
      if( r != 0) {
        out("No");
        return;
      }
      r = i;
    }
  }
  
  //順序を設定
  order[r] = N;


  //順序が1になるまで以下を実施
  while(order[r] > 1) {
    ll nx = 0;

    //対象のノードからの行き先次数を減少させ0になるもの（rからしかいけないもの）を次の対象とする
    //ただし、本問題は一意性が重要なので、チェックして複数あった場合にはエラー。
    for(auto g :G[r]) {
      deg[g] --;
      if(deg[g] == 0) {
        
        if( nx != 0) {
          out("No");
          return;
        }
        nx = g;
      }
    }

    //次のものが見つかったら順序を設定
    order[nx] = order[r] -1;
    r = nx;
  }

  //結果を出力
  out("Yes")
  reps(i,1,N+1) {
    out2(order[i])
    out2(" ")
  }

}




int main()
{
  solve();
	return 0;
}