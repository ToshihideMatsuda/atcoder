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


void solve() {
  ll H, W; cin >> H >> W;
  ll A[H][W]; rep(h,H) rep(w,W) cin >> A[h][w];
  ll Hs[W],Ws[H];

  rep(w,W){
    Hs[w] = 0;
    rep(h,H) Hs[w] += A[h][w];
  }

  rep(h,H){
    Ws[h] = 0;
    rep(w,W) Ws[h] += A[h][w];
  }
  rep(h,H){ 
    rep(w,W) cout << Hs[w] + Ws[h] - A[h][w] << " ";
    cout << endl;
  }

}


int main()
{
  solve();
	return 0;
}