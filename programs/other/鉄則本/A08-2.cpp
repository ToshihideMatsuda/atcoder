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

void solve() {
  ll H, W; cin >> H >> W;
  ll X[H+2][W+2]; 
  rep(h,H+2)rep(w,W+2)X[h][w] = 0;

  reps(h,1,H+1) reps(w,1,W+1) cin >> X[h][w];

  ll S[H+1][W+1];
  rep(h,H+1)rep(w,W+1) S[h][w] = 0;
  
  reps(h,1,H+1) reps(w,1,W+1) S[h][w] = X[h][w];
  reps(h,1,H+1) reps(w,1,W+1) S[h][w] = S[h][w-1] + S[h][w]; // 横方向の累積和
  reps(w,1,W+1) reps(h,1,H+1) S[h][w] = S[h-1][w] + S[h][w]; // 縦方向の累積和

  ll Q; cin >> Q;
  rep(_, Q) {
    ll A, B, C, D; cin >> A >> B >> C >> D;
    cout << S[C][D] - S[A-1][D] - S[C][B-1] + S[A-1][B-1] << endl;
  }

}


int main()
{
  solve();
	return 0;
}