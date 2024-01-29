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

#define MAX_N 25

ll d[MAX_N][MAX_N];
ll N, M;
void warshall_floyd() {
  rep(k,N) {           // 経由する頂点
      rep(i,N) {       // 始点
          rep (j,N) {  // 終点
              d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
          }
      }
    }
}


int main()
{
	
	cin >> N >> M;

	rep(i,MAX_N) rep(j,MAX_N) d[i][j] = (i == j ? 0 : INF_LL);
	rep(i,M) {
		ll u, v, w;
		cin >> u >> v >> w;
		u--;
		v--;
  		d[u][v] = w;
	}

	warshall_floyd();

	vector dp = vector( (1 << N) , vector(N,INF_LL) );

	rep(i,N) {
		dp[(1 << i)][i] = 0;
	}

	for(ll S = 1; S < (1 << N)-1; S ++) {
		rep(i,N) if( (S &(1 <<i)) > 0 && dp[S][i] < INF_LL){
			rep(j,N) if( d[i][j] < INF_LL){
				dp[S|(1<<j)][j]	= MIN(dp[S|(1<<j)][j], dp[S][i] + d[i][j]);
			}
		}
	}

	ll ans = INF_LL;
	rep(i,N) {
		ans = MIN(ans, dp[(1 << N) -1][i]);
	}
	
	if(ans == INF_LL) {
		out("No")
	} else {
		out(ans)
	}


	return 0;
}
