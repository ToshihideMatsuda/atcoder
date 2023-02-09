#include <bits/stdc++.h> 
#include <unordered_map>

using namespace std;

#define debug false

#define rep(i,n)     for(int i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(int i = m; i < n; i++ ) 


typedef long long ll;

#define INF 1 << 28
#define MOD 998244353

void solve(){
  ll H, W; cin >> H >> W;
  char A[H+1][W+1];
  rep(h,H)rep(w,W) cin >> A[h+1][w+1];
  ll Q; cin >> Q;

  vector<pair<ll,ll>> p = {{1,1},{1,2},{2,1}};
  rep(i,Q) {
    ll a, b;
    cin >> a >> b;

    rep(i,3) {
      if(p[i].first <= a){
        p[i].first = (a+1)-p[i].first;
      } else {
        p[i].first = (H - a + 1) - (p[i].first - a) + a;
      }

      if(p[i].second <= b){
        p[i].second = (b+1)-p[i].second;
      } else {
        p[i].second = (W - b + 1) - (p[i].second - b) +b;
      }
    }
  }

  ll x[H+1];
  ll y[W+1];

  ll xd = ((p[0].first + 1) % H + 1 == (p[2].first) % H  + 1) ? 1 : -1;
  ll yd = ((p[0].second +1) % W + 1 == (p[1].second) % W  + 1) ? 1 : -1;

  ll xi = p[0].first;
  ll yi = p[0].second;

  reps(i,1,H+1){
    x[xi] = i;
    xi += xd;
    if(xi == H+1) xi = 1;
    else if(xi == 0) xi = H;
  }
  
  reps(i,1,W+1){
    y[yi] = i;
    yi += yd;
    if(yi == W+1) yi = 1;
    else if(yi == 0) yi = W;
  }

  reps(i,1,H+1){
    reps(j,1,W+1) cout << A[x[i]][y[j]] ;
    cout << endl;
  }

    
  return;
}

int main(){

	solve();

    return 0;
}

