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

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}


void solve() {
    ll N; cin >> N;
    ll dp[N+5][N+5];
    rep(i,N+5)rep(j,N+5) dp[i][j] =0;
    dp[0][0] = 1;

    rep(i,N) {
        rep(j,i+1) {
            if(j == 0)
                dp[i+1][0] = 1;
            else
                dp[i+1][j] = dp[i][j-1] + dp[i][j];
        }
        rep(j,i+1) cout << dp[i+1][j] << " ";
        cout << endl;
    }
}


int main()
{
  solve();
	return 0;
}