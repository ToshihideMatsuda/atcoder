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
#define out(s)  cout << s << endl;
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
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


int main()
{
	ll n; cin >> n;
	double dp[2][n+1];
	dp[0][0] = 200;
	dp[1][0] = 200;

	vector<pair<ll,ll>> xy;
	rep(i,n) {
		ll x,y;cin >> x >> y;
		xy.push_back({x,y});
	}

	sort(xy.begin(),xy.end());
	reps(i,1,n+1) {
		auto [x, y] = xy[i-1];
		if(i == 1) {
			dp[0][1] = (100.0 - y)/2.0;
			dp[1][1] = abs(- 100.0 - y)/2.0;
		} else {
			auto [prex, prey] = xy[i-2];

			double r = sqrt( (prex - x)*(prex - x) +  (prey - y)*(prey - y) ) / 2.0 ;

			dp[0][i] = MIN(
							MAX(dp[0][i-1],			   //下のまま
								MIN(dp[1][i-1], r)),   // 上から下へ
							abs(100.0 - y)/2.0 //下のまま
						); 

			dp[1][i] = MIN(
							MAX(dp[1][i-1],			   //下のまま
								MIN(dp[0][i-1], r)),   // 上から下へ
							abs(- 100.0 - y)/2.0 //下のまま
						); 
		}
	}

	outd(MAX(dp[0][n],dp[1][n]))


	return 0;
}