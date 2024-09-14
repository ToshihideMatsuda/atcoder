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
#define INF_LL  (9223372036875807LL)
#define MINF_LL (-9223372036854775808LL)
#define MOD 998244353

#define MAX_N 400 + 5


 // グラフの隣接行列
 // 配列d[a][b]には頂点a,b間の辺のコストを入れておき、a=bの時は0を、a,b間の辺が存在しないときはINFを入れておく。
 //
 // rep(i,MAX_N) rep(j,MAX_N) d[i][j] = (i == j ? 0 : INF);
 // rep(i,M){
 //   ll a, b, c;
 //   cin >> a >> b >> c;
 //   d[a][b] = c;
 //   d[b][a] = c;
 // }

ll d[MAX_N][MAX_N];
ll N=0, M=0; 
void warshall_floyd() {
  reps(k,1,N+1) {           // 経由する頂点
      reps(i,1,N+1) {       // 始点
          reps (j,1,N+1) {  // 終点
              d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
          }
      }
    }
}

int main()
{
cin >> N >> M;

	vector<tuple<ll,ll,ll>> UVT(M+1);
	rep(i,MAX_N) rep(j,MAX_N) d[i][j] = (i == j ? 0 : INF_LL);
	rep(i,M) {
		ll u,v,t;
		cin >> u >> v >> t;
		UVT[i+1] = {u,v,t};
		d[u][v] = MIN(d[u][v],t);
		d[v][u] =  MIN(d[v][u],t);
	}

	warshall_floyd();
	ll Q; cin >> Q;
	while(Q--) {
		ll K; cin >> K;
		vector<ll> B(K);
		rep(i,K) cin >> B[i];
		ll ans = INF_LL;
		do {
			for(int j = 0; j < (1 << 5); j ++) {
				ll p = 1;
				ll ttt = 0;
				rep(i,K) {
					auto [u, v, t] = UVT[B[i]];

					bool swap  = (j & (1 << i)) > 0;

					if(swap) {
						ll tmp = u;
						u = v;
						v = tmp; 
					}

					ttt += d[p][u];
					ttt += t;
					p = v; 
				}

				ttt += d[p][N];
				if(ttt == 0) {
					ll aaa = 0;
				}

				ans = MIN(ttt,ans);
			}





		} while(next_permutation(B.begin(),B.end()));
		out(ans);
	}

	return 0;
}