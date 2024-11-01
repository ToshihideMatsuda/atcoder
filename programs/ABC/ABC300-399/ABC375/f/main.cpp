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
#define INF  (922337203685477580LL)
#define MINF_LL (-9223372036854775807LL)
#define MOD 998244353
#define MAX_N 300 + 5


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

ll N, M, Q;
ll d[MAX_N][MAX_N];


void warshall_floyd() {
  rep(k,N) {           // 経由する頂点
      rep(i,N) {       // 始点
          rep (j,N) {  // 終点
              d[i][j] = MIN(d[i][j], d[i][k] + d[k][j]);
          }
      }
    }
}


void warshall_floyd2(ll k1, ll k2) {

	rep(i,N) {       // 始点
        rep (j,N) {  // 終点
              d[i][j] = MIN3(d[i][j], 
			  				d[i][k1] + d[k1][k2] + d[k2][j], 
							d[i][k2] + d[k2][k1] + d[k1][j]);
        }
    }
}


int main()
{
	cin >> N >> M >> Q;
	
	vector<tuple<ll,ll,ll>> ABC(M);
	vector<bool> alive(M,true);
	
	vector<tuple<ll,ll,ll>> Query(Q);

	rep(i,M) {
		ll a, b, c; cin >> a >> b >> c;
		a--;b--;
		ABC[i] = {a,b,c};
	}

	rep(i,Q) {
		ll t; cin >> t;
		ll x=-1,y=-1; 
		cin >> x;
		x--;
		if(t == 1){
			alive[x] = false;
		}else if(t == 2) {
			cin >> y;
			y--;
		} 

		Query[i] = {t,x,y};
	}

 	rep(i,MAX_N) rep(j,MAX_N) d[i][j] = (i == j ? 0 : INF);

	for(int i = 0; i < M;i++) if(alive[i] == true) {
		auto [a,b,c] = ABC[i];
		d[a][b] = c;
		d[b][a] = c;
	}

	warshall_floyd();

	stack<ll> sta;

	for(int i = Q-1; i > -1; i--) {
		auto [t,x,y] = Query[i];
		if(t == 1) {
			auto [a,b,c] = ABC[x];
			if(c < d[a][b]) {
				d[a][b] = c;
				d[b][a] = c;

				warshall_floyd2(a,b);
			}
		} else {
			sta.push(d[x][y]);
		}
	}

	while(sta.size() > 0) {
		ll d = sta.top(); sta.pop();
		if(d == INF) {
			out(-1)
		} else {
			out(d)
		}
	}


	return 0;
}