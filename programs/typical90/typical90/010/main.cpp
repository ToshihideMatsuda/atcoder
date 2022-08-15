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
  ll N; cin >> N;
  ll P[3][N+1];
  rep(i,3)rep(j,N+1)P[i][j] = 0;
  reps(i,1,N+1) {
    ll c, p; cin >> c >> p;
    P[c][i] = p;
  }

  ll S[3][N+1];
  S[1][0] = 0; S[2][0] = 0;
  reps(c,1,3)reps(i,1,N+1) S[c][i] = S[c][i-1] + P[c][i];


  ll Q; cin >> Q;
  vector<pair<ll,ll>> LR(Q);
  rep(i,Q) {
    ll l, r; cin >> l >> r;
    LR[i] = {l,r};
  }
  for(auto lr : LR){
    ll l = lr.first, r = lr.second;
    cout << S[1][r] - S[1][l-1] << " " <<  S[2][r] - S[2][l-1] << endl;
  }


}


int main()
{
  solve();
	return 0;
}