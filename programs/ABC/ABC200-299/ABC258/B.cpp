#include <bits/stdc++.h> 
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


void solve() {
  ll N;
  cin >> N;
  ll A[3*N][3*N];

  rep(i,N) {
    string s;
    cin >> s;
    rep(j,N) {
      ll a = s[j] - '0';
      A[i][j]     = a;
      A[i][j+N]   = a;
      A[i][j+2*N]   = a;
    
      A[i+N][j]   = a;
      A[i+N][j+N] = a;
      A[i+N][j+2*N]   = a;
      A[i+2*N][j]   = a;
      A[i+2*N][j+N] = a;
      A[i+2*N][j+2*N]   = a;
    }
  }

  ll ans = 0;

  pair<ll,ll> d[8] = {
    {1,0},
    {-1,0},
    {0,1},
    {0,-1},
    {1,1},
    {-1,1},
    {1,-1},
    {-1,-1},
  };

  reps(i,N,2*N)reps(j,N,2*N) {

    ll tmp[8];
    rep(k,8) tmp[k] =0;
    rep(k,N) {
      rep(m,8) {
        tmp[m] = 10*tmp[m] + A[i + k*d[m].first][j + k*d[m].second];
      }
    }
    rep(k,8) ans = max(ans,tmp[k]); 
  } 
  cout << ans << endl;
}


int main()
{
  solve();
	return 0;
}