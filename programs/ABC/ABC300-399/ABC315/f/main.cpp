#include <bits/stdc++.h> 

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

double dif(ll i, ll j, vector<pair<double,double>>& XY) {
	auto [x,y] = XY[i];
	auto [a,b] = XY[j];
	return sqrt((x-a)*(x-a) + (y-b)*(y-b));
}

double dp[10000+1][35];
int main()
{
	ll N; cin >> N;
	vector<pair<double,double> > XY;
	XY.push_back({-1,-1});
	rep(i,N) {
		double x, y; cin >> x >> y;
		XY.push_back({x,y});
	}

	rep(i,10000+1)rep(k,35) dp[i][k] = 1e18;
	dp[1][0] = 0;

	double p[35];
	p[0] = 0;
	p[1] = 1;
	reps(i,2,35) p[i] = p[i-1] * 2;

	 for(int to=2;to<N+1;to++){
		for(int from=1; from <= to-1;from++){
			ll skip = (to-1) - from;
			for(ll k = 0; (k + skip) < 35; k ++) {
				dp[to][k+skip] = MIN(dp[to][k+skip], dp[from][k] + dif(to,from,XY));
			}
		}
	}


	double ans = INF_LL;
	rep(k,35) {
		ans = MIN(dp[N][k] + p[k], ans);
	}
	outd(ans)


	return 0;
}