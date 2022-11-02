#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i-- ) 
#define revs(i,m,n)  for(ll i = m; i > n; i++ ) 
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


void solve(){
	ll N; cin >> N;
	vector<ll> H(N+1); rep(i,N) cin >> H[i+1];
	vector<ll> dp(N+1, INF_LL);

	dp[1] = 0;
	reps(i,1,N) {
		if(i+1 <= N) dp[i+1] = MIN(dp[i+1],dp[i] + abs(H[i+1] - H[i]));
		if(i+2 <= N) dp[i+2] = MIN(dp[i+2],dp[i] + abs(H[i+2] - H[i]));
	}
	cout << dp[N] << endl;

}

int main(){
    solve();
    return 0;
}

