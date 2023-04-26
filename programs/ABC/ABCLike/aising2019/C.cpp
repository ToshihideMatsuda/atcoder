#include <bits/stdc++.h> 
using namespace std;
typedef long long ll;
#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) MIN(a,MIN(b,c))

int main()
{
  ll H, W; cin >> H >> W;
  vector<string> S(H);rep(i,H) cin >> S[i];
  bool ck[H+2][W+2];
  int b[H+2][W+2];
  rep(h,H+2)rep(w,W+2) ck[h][w] = false;
  rep(h,H+2)rep(w,W+2) b[h][w] = 0; 
  rep(h,H)rep(w,W) if(S[h][w] == '#') b[h+1][w+1] = 1; else b[h+1][w+1] = -1;

  ll dx[4] = { 1, -1, 0, 0};
  ll dy[4] = { 0, 0, 1, -1};

  ll ans = 0;
  reps(h,1,H+1)reps(w,1,W+1) if(ck[h][w] == false && b[h][w] == 1) {
    queue<pair<ll,ll>> Q;
    Q.push({h,w});
    ll bl = 1, wt = 0;
    ck[h][w] = true;

    set<pair<ll,ll>> s;

    while(Q.size() > 0) {
      ll r,c;
      tie(r,c) = Q.front();Q.pop();
      rep(i,4) {
        ll nr = r + dx[i], nc = c + dy[i];
        if(b[r][c] == 1 && b[nr][nc] == -1){
          if(!s.count({nr,nc})) {
            s.insert({nr,nc});
            wt++;
            Q.push({nr,nc});
          }
        } else if(b[r][c] == -1 && b[nr][nc] == 1) {
          if(ck[nr][nc] == false) {
            ck[nr][nc] = true;
            bl++;
            Q.push({nr,nc});
            continue;
          }
        }
            
      }
    }
    ans += bl * wt;
  }
  cout << ans << endl;

  return 0;
}