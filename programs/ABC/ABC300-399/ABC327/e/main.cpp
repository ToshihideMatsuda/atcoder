#include <bits/stdc++.h> 
#include <atcoder/all>

using namespace atcoder;
using namespace std;
// 多倍長テンプレ（デバッグだとダメかも）
/* ---------------------- ここから ---------------------- */
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
// 任意長整数型
using bll = mp::cpp_int;
// 仮数部が10進数で1024桁の浮動小数点数型(TLEしたら小さくする)
using real = mp::number<mp::cpp_dec_float<1024>>;
/* ---------------------- ここまで ---------------------- */

typedef long long ll;

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

double dp[5005][5005];

int main()
{
	ll N; cin >> N;
	vector<ll> P(N+1);
	rep(i,N) cin >> P[i+1];

	vector<double> R(5005);
	vector<double> Q(5005);
	vector<double> S(5005);
	R[0] = 0;
	reps(i,1,5000+5) R[i] = 1200.0/sqrt(i);

	Q[0] = 1;// S[0] = 1, Q[1] = 0.9, Q[2] = 0.9^2
	reps(i,1,5000+5) Q[i] = (Q[i-1] * 0.9);

	S[0] = 1;// S[0] = 1, S[1] = 1, S[2] = 1+ 0.9
	S[1] = 1;
	reps(i,2,5000+5) S[i] = S[i-1] + Q[i-1];


	rep(i,5000+5)rep(j,5000+5) dp[i][j] = MINF_LL;
	rep(i,N) dp[i][0] = 0;

	reps(i,1,1+N) {
		rep(k,i) {
			double pp =  ((dp[i-1][k] + R[k]) * S[k] * 0.9 + P[i])/S[k+1];
			double val = pp - R[k+1];
			dp[i][k+1]  = MAX(dp[i-1][k+1], val);
		}
	}

	double ans = MINF_LL;
	reps(i,1,N+1) ans = MAX(dp[N][i], ans);
	outd(ans)




	return 0;
}