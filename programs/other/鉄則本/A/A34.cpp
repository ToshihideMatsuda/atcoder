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

#define MAX_N 300000 + 5



/*
** Grundy数の計算
** Grundy数 := if 手番なし <=> Grundy数 = 0
**             if 遷移先が x1, x2,...,xm だった場合、G = mex(x1, x2,...,xm) （x1, x2,...,xmに含まれない最小の非負整数）
** 意味合い : Grundy数が0 <=> 後手必勝、 Grundy数が0以外 <=> 先手必勝
**          なぜならば、
**          Grundy数が0 <=> 0に遷移することができないので、相手が必ずGrundy数が1以上になる
**          Grundy数が1以上 <=> 0に遷移することが可能なので、その手を取れば、相手が必ずGrundy数が0になる
**
** 補足: Gは各山xorの値と一致する（スプレイグ・グランディの定理）ので以下のようになる
**       G = G[1] xor G[2] xor ... G[N]
*/


ll N, X, Y; 
ll G[100000 + 5];

void initGrundy() {
  // 0 <= x < X は G[x] = 0;
  rep(x,X) G[x] = 0; 
 
  reps(x, X, 100001) {
    bool toGrundy[3] = {false, false, false};
    if(0 <= x-X) toGrundy[G[x-X]] = true; 
    if(0 <= x-Y) toGrundy[G[x-Y]] = true; 
 
    rep(i,3) if(toGrundy[i] == false) {
      G[x] = i;
      break;
    }
  }
}


int main()
{
  cin >> N >> X >> Y;
  initGrundy();

  vector<ll> A(N); rep(i,N) cin >> A[i];

  ll allG = 0;
  rep(i,N) allG ^= G[A[i]];


  if(allG == 0) { 
    // Grundy数が0 <=> 後手必勝
    cout << "Second" << endl;
  } else {
    // Grundy数が0以外 <=> 先手必勝
    cout << "First" << endl;
  }



}