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


#define INF (2147483647)
#define MINF (-2147483648)
#define INF_LL  (9223372036854775807LL)
#define MINF_LL (-9223372036854775807LL)
#define MOD 998244353

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


using mint = modint998244353;


int main()
{
	ll N; cin >> N;
	vector<ll> A(N);
	rep(i,N) cin >> A[i];

	// dp[n][m][c][r]: 初項がAm, 終項がAn, 項数c, 公差がr の個数
	auto dp = vector(N+1, vector(N+1,vector<map<ll,mint>>(N+1)));
	
	rep(i,N) {
		dp[i][i][1][0] = 1;
		rep(j,i) {
			ll R = A[i] - A[j];
			dp[j][i][2][R] = 1;
			rep(k,j) {
				rep(l,N) {
					if(dp[k][j][l].count(R)) {
						dp[k][i][l+1][R] += dp[k][j][l][R];
					}
				}
			}
		}
	}

	vector<mint> L(N+1);
	reps(l,1,N+1) {
		rep(i,N+1)reps(j,i,N+1) {
			for(auto idx = dp[i][j][l].begin(); idx != dp[i][j][l].end(); ++idx) {
				L[l] += (*idx).second;
			}
		}
		out0(L[l].val())
		out0(" ")
	}




	
	return 0;
}