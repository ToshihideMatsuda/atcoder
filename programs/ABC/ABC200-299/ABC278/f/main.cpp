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

#define MAX_N 2*100000+5
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

// dp[S][c] :: 集合S={s0,s1,..,sn}の文字が残存している状態で、前回の末尾がc（cから開始）の場合に勝つか負けるか
bool dp[(1 << 16) + 5][26];
void solve() {
  ll N; cin >> N;
  vector<string> S(N);
  rep(i,N) cin >> S[i];

  reps(s,1,(1 << N)) {
    rep(c,26) {
      bool ok = false;
      rep(i,N) {
        //i番目の文字列が選択可能か判定
        if( S[i].front() - 'a' == c && ((s & (1 << i) ) > 0) ){
          //i番目の文字列選択時に相手を負け状態に持ち込めるならば、自分は勝ち状態
          if(dp[s ^(1 << i)][S[i].back() - 'a'] == false) ok = true;
        }
      }
      dp[s][c] = ok;
    }
  }

  bool first = false;
  rep(c,26) if(dp[(1<<N) - 1][c]) first = true;

  if(first) {
    cout << "First" << endl;
  } else {
    cout << "Second" << endl;
  }


}


int main()
{
  solve();
	return 0;
}