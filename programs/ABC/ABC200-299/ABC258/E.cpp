#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define max(a,b)   (a>b?a:b)
#define max3(a,b,c) max(a,max(b,c))
#define min(a,b)   (a<b?a:b)
#define min3(a,b,c) min(a,min(b,c))


#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5


void solve() {
  ll N, Q, X;
  cin >> N >> Q >> X;
  vector<ll> W(N); // 0...N-1のじゃがいもの重さ
  rep(i,N) cin >> W[i];

  // 1) R : じゃがいもの重さの累積和（ループを考慮して２回ループ）
  vector<ll> R(2*N+1); 
  R[0] = 0;
  reps(i,1,2*N+1)  R[i] = R[i-1] + W[(i-1)%N];
  ll Sum = R[N];

  // 2) Box : i番目から始めた場合の箱に詰めるじゃがいもの個数
  //          尺取り方でRを対象に算出
  vector<ll> Box(N); 
  ll ed = 1;
  rep(i,N) {
    ll Q = (X / Sum) * N ; // ループ回数
    ll Y = X % Sum;         // 残数
    while(R[ed] - R[i] < Y) ed++;
    Box[i] = Q + ed - i;
  }

  // 3) path : 鳩の巣原理より、じゃがいもの個数のSumはN回以内にループする。
  //           その際のパス
  ll tmp = 0;
  vector<ll> path;
  path.push_back(tmp);
  while(true) {
    tmp = (tmp + Box[tmp]) % N;
    if( count(path.begin(), path.end(),tmp) > 0 )  break;
    path.push_back(tmp);
  }

  // 4) loop, non_loop : path内のloopとnon_loopのパスの長さを取得
  ll loop=0, non_loop=0;
  ll t = 0;
  while(t != tmp){
    non_loop++;
    t = (t + Box[t]) % N;
  }

  loop ++;
  set<ll> s;
  s.insert(t);
  while(true) {
    t = (t + Box[t]) % N;
    if(s.count(t)) break;
    
    loop++;
    s.insert(t);
  }

  // 5) Kに応じてpathを使用してBoxを取得
  rep(_,Q) {
    ll K;
    cin >> K;
    K--;
    
    if(K < non_loop ) {
      cout << Box[ path[K] ]<< endl;
    } else {
      ll inloop = (K - non_loop) % loop;
      cout << Box[ path[inloop + non_loop ] ] << endl;
    } 
  }


  
}


int main()
{
  solve();
	return 0;
}