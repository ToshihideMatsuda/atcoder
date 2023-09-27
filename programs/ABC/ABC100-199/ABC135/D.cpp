#include <bits/stdc++.h> 
#include <atcoder/all>
using namespace atcoder;


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
#define MOD (1000000007)

#define MAX_N 2*100000+5

using mint = modint1000000007;

int main()
{
	string s; cin >> s;

  auto dp = vector<vector<mint>>( s.size()+1, vector<mint>(13,0)) ;

  dp[s.size()][0] = 1;
  ll ten = 1;

  for(int i = s.size()-1; i >=0; i--) {
    if(s[i] == '?') {
      rep(j,10) {
        mint v = ten * j ;
        rep(k,13) {
          dp[i][(k + v.val())%13] += dp[i+1][k];
        }
      }
    } else {
      mint v = ten * (s[i] - '0');
      rep(k,13) {
        dp[i][(k + v.val())%13] = dp[i+1][k];
      }
    }
    ten *= 10;
    ten %= 13;
  }

  cout << dp[0][5].val() << endl;

	return 0;
}
