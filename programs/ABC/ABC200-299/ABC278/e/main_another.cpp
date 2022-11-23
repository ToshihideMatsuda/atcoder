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

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

void solve() {
  ll H, W, N, h, w; 
  cin >> H >> W >> N >> h >> w;
  vector<vector<ll>> A(H);

  unorderd_map<ll,ll> maxX;
  unorderd_map<ll,ll> maxY;
  unorderd_map<ll,ll> minX;
  unorderd_map<ll,ll> minY;

  rep(i,H){
    vector<ll> AA(W+5);
    rep(j,W) {
      cin >> AA[j];
      maxX[A[j]] = max(maxX[A[j]],i);
      maxY[A[j]] = max(maxY[A[j]],j);
      minX[A[j]] = min(minX[A[j]],i);
      minY[A[j]] = min(minY[A[j]],j);
    }
    A[i]=move(AA);
  }
  
  rep(i,H-h)rep(j,W-w) {
    ll ans = 0;
    reps(l,i,i+h)reps(m,j,j+w)rep(i,N+1) {

    }
  }



}


int main()
{
  solve();
	return 0;
}