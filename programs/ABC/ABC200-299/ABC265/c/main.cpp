#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) max(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) min(a,MIN(b,c))

#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5


char G[505][505];

void solve() {
  ll H, W; cin >> H >> W;
  rep(h,505)rep(w,505) 
    G[h][w] = '*';
  rep(h,H)rep(w,W) cin >> G[h+1][w+1];

  pair<ll,ll> s = {1,1};
  pair<ll,ll> ans = s;

  while(true) {
    ll h,w;
    tie(h,w) = s;
    if(G[h][w] == 'U') {
      s = {h-1,w};
    } else if(G[h][w] == 'D') {
      s = {h+1,w};
    } else if(G[h][w] == 'L') {
      s = {h,w-1};
    } else if(G[h][w] == 'R') {
      s = {h,w+1};
    } else if(G[h][w] == '*'){
      //kabe
      cout << ans.first << " " << ans.second << endl;
      return;
    } else if (G[h][w] == '-') {
      cout << "-1" << endl;
      return;
    }

    G[h][w] = '-';
    ans = {h,w};

  }



}


int main()
{
  solve();
	return 0;
}