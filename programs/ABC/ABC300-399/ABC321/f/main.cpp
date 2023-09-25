#include <bits/stdc++.h> 
#include <atcoder/all>
using namespace atcoder;
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) MIN(a,MIN(b,c))
#define out0(s) cout << s;
#define outl(s)  cout << s << endl;
#define outd(s) cout << setprecision(15) << s << endl;
#define pb(s) push_back(s)
/*
	vector<ll> X = {4,7,3,1,7,9,4};
	SORT(X, <)
	OUT(X,",") //1,3,4,4,7,7,9,

	SORT(X, >)
	OUT(X," ") //9 7 7 4 4 3 1
*/
#define SORT(A,R) std::sort((A).begin(),(A).end(), [](auto const& x, auto const& y) { return x R y; });
#define OUT(A,separate) for(auto a : A) { cout << a << separate; }


#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353


#define MAX_N (2*100000+5)

using mint = modint998244353;

int main()
{
	ll Q, K; cin >> Q >> K;
	vector<mint> dp(K+1,0);
	dp[0] = 1;
	vector<ll> ans;
	while(Q--) {
		char c; cin >> c;
		ll x; cin >> x;

		vector<mint> dp2(dp);

		if(c == '+') {
			rep(i,K+1) {
				if(i-x >= 0) dp2[i] += dp[i-x];
			}
		} else {
			rep(i,K+1) {
				if(i-x >= 0) dp2[i] -= dp2[i-x];
			}
		}
		
		dp = move(dp2);
		ans.push_back(dp[K].val());
	}

	OUT(ans,endl)

	
	return 0;
}