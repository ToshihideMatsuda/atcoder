#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i-- ) 
#define revs(i,m,n)  for(ll i = m; i > n; i-- ) 
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


ll dp[100+ 5][1000 * 100 + 5];

void solve(){
	ll N, W; cin >> N >> W;

	rep(i,100+5)rep(j,1000 * 100 + 5) dp[i][j] = INF_LL;
	dp[0][0] = 0;

	reps(i,1,N+1) {
		ll w, v; cin >> w >> v;
		rep(j,1000 * 100 + 5){
			if(j - v >= 0) dp[i][j] = min(dp[i-1][j], dp[i-1][j - v] + w);
			else dp[i][j] = dp[i-1][j];
		}
	}

	ll ans = 0;
	rep(j,1000 * 100 + 5) if(dp[N][j] <= W){ ans = j; }
	cout << ans << endl;


}

int main(){
    solve();
    return 0;
}

