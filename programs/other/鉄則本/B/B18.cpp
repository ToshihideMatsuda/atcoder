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


void solve(){
	ll N, S; cin >> N >> S;
	vector<ll> A(N);rep(i,N) cin >> A[i];

	vector<ll> dp[S+1];
	dp[0] = {-1};

	rep(i,N) {
		revs(s, S-1, -1) if(dp[s].size() > 0 && s + A[i] <= S) {
			vector<ll> tmp(dp[s]);
			dp[s + A[i]] = tmp;
			dp[s + A[i]].push_back(i+1);
			if(s + A[i] == S) break;
		}
	}

	if(dp[S].size() == 0) {
		cout << -1 << endl;
	} else {
		cout << dp[S].size() -1 << endl;
		for(auto s : dp[S]) if(s >= 0)cout << s << " ";
		cout << endl;
	}



}

int main(){
    solve();
    return 0;
}

