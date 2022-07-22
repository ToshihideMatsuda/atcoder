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

double dp[101][101][101];


void solve() {
  ll A,B,C; cin >> A >> B >> C;
  dp[A][B][C] = 1;
  reps(a,A,100) reps(b,B,100) reps(c,C,100) {
    dp[a+1][b][c] += dp[a][b][c]*((double)a/(double)(a+b+c));
    dp[a][b+1][c] += dp[a][b][c]*((double)b/(double)(a+b+c));
    dp[a][b][c+1] += dp[a][b][c]*((double)c/(double)(a+b+c));
  }

/*
  cout << dp[100][99][99] << endl; // 0.11036
  cout << dp[99][100][99] << endl; // 0.11036
  cout << dp[99][99][100] << endl; // 0.11036
  cout << dp[98][100][99] << endl; // 0.334459
  cout << dp[98][99][100] << endl; // 0.334459
*/
  double ans = 0;
  reps(a,A,101)reps(b,B,101)reps(c,C,101) 
  if(
    (a == 100 && b <  100 && c <  100) ||
    (a <  100 && b == 100 && c <  100) ||
    (a <  100 && b <  100 && c == 100)
  ) {
    double cnt = (a - A) + (b - B) + (c - C);
    ans += cnt * dp[a][b][c];
  }



  cout << setprecision(15) << ans << endl;
}


int main()
{
  solve();
	return 0;
}