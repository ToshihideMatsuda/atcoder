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

ll XY[1505][1505];
ll S[1505][1505];
void solve() {
  ll N; cin >> N;;
  rep(i,N) {
    ll X, Y; cin >> X >> Y;
    XY[X][Y] ++;
  }
  reps(x,1, 1501) reps(y,1,1501) S[x][y] = S[x][y-1] + XY[x][y]; // 横方向に加算
  reps(x,1, 1501) reps(y,1,1501) S[x][y] = S[x-1][y] + S[x][y];  // 列方向に加算
  

  ll Q; cin >> Q;
  vector<ll> ans;
  rep(i,Q) {
    ll a, b, c, d; cin >> a >> b >> c >> d;
    ans.push_back(S[c][d] - S[a-1][d] - S[c][b-1] + S[a-1][b-1]); 
  }
  rep(i,ans.size()) cout << ans[i] << endl;
  



}


int main()
{
  solve();
	return 0;
}