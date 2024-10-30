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
#define MINF_LL (-9223372036854775808LL)
#define MOD 998244353

#define MAX_N (2*100000+5)
vector<pair<ll,ll>> G[MAX_N], H[MAX_N];

int main()
{
	ll N,M; cin >> N >> M;
	vector<bool> leaf(N+1,true); 
	rep(i,M){
		ll u,v,w;cin >> u >> v >> w; 
		G[u].push_back({v,w});
		H[v].push_back({u,w});
		leaf[u] = false;
	}
	vector<ll> x(N+1,INF_LL);
	/*
	for(int v = 1; v < N+1;v++) 
		if(leaf[v]== true && x[v] == INF_LL){
		x[v] = 0;

		queue<ll> Q;
		Q.push(v);
		while(Q.size()>0) {
			auto v = Q.front();Q.pop();

			for(auto [u,w]: H[v]) if(x[u] == INF_LL) {
				x[u] = x[v]-w;
				Q.push(u);
			}
		}
	}
	*/

	for(int v = 1; v < N+1;v++) if(x[v] == INF_LL){
		x[v] = 0;

		queue<ll> Q;
		Q.push(v);
		while(Q.size()>0) {
			auto v = Q.front();Q.pop();

			for(auto [u,w]: H[v]) if(x[u] == INF_LL) {
				x[u] = x[v]-w;
				Q.push(u);
			}

			for(auto [uu,w]: G[v]) if(x[uu] == INF_LL) {
				 x[uu] = x[v] + w;
				Q.push(uu);
			}
		}
	}

	
	rep(i,N){
		out0(x[i+1])
		out0(" ")
	}


	return 0;
}

/*
4 4
1 2 1
2 3 1
3 1 -2
4 1 1
*/