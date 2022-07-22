#include <bits/stdc++.h> 
#include <unordered_map>
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

ll dis[2005][2005];


void solve() {

  clock_t start = clock();
  ll H, W; 
  cin >> H >> W;

  char a[H+2][W+2];
  pair<ll,ll> s,g;
  vector<pair<ll,ll>> az[26];
  rep(h,H+2)rep(w,W+2)a[h][w] = '.';
  rep(h,H+2) {
    a[h][0]   = '#';
    a[h][W+1] = '#';
  }
  rep(w, W+2) {
    a[0][w]   = '#';
    a[H+1][w] = '#';
  }

  reps(h,1,H+1)reps(w,1,W+1) cin >> a[h][w];

  reps(h,1,H+1)reps(w,1,W+1) {
    if(a[h][w] == '#') continue;
    if(a[h][w] == 'S') s = {h,w};
    else if (a[h][w] == 'G') g = {h,w};
    else if ('a' <= a[h][w] && a[h][w] <='z') {
      az[a[h][w] - 'a'].push_back({h,w});
    }
  }


  queue<pair<ll,ll>> Q;
  Q.push(s);
  rep(i,2005)rep(j,2005) dis[i][j] = INF_LL;
  dis[s.first][s.second] = 0;
  pair<ll,ll> d[4] = { {1,0},{-1,0}, {0,1},{0,-1}};

  while(Q.size() > 0) {
    pair<ll,ll> q = Q.front();Q.pop();

    rep(i,4) {
      pair<ll,ll> u = {q.first + d[i].first, q.second + d[i].second};
      if(a[u.first][u.second] != '#') {
        if(dis[q.first][q.second] + 1 < dis[u.first][u.second] ) {
          dis[u.first][u.second] = dis[q.first][q.second] + 1;
          Q.push(u);
        }
      }
    }
    char ch = a[q.first][q.second];
    if ('a' <= ch && ch <='z') {
      for( auto u : az[ch - 'a']){

        if(dis[q.first][q.second] + 1 < dis[u.first][u.second] ) {
          dis[u.first][u.second] = dis[q.first][q.second] + 1;
          Q.push(u);
        }
      }
      //1回だけ使用
      az[ch - 'a'].clear();
    }
  }


  if(dis[g.first][g.second] == INF_LL) {
    cout << -1 << endl;
    return;
  }
  cout << dis[g.first][g.second] << endl;

  


}


int main()
{
  solve();
	return 0;
}