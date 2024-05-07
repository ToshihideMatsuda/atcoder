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

#define MAX_N  (100000+5)

int main()
{
	ll N, M; cin >> N >> M;
	vector<ll> G[MAX_N], G2[MAX_N], H[MAX_N];

	vector<vector<ll>> ck(MAX_N,vector<ll>(3,-1)); 

	rep(i,M) {
		ll u, v; cin >> u >> v;
		G[u].push_back(v);
	}
	ll S, T; cin >> S >> T;
	


	queue<pair<ll,ll>> Q;
	Q.push({S,0});
	ck[S][0] = 0;


	while(Q.size() > 0) {
		auto [q,t] = Q.front();Q.pop();
		
		for(auto g: G[q])if(ck[g][(t+1)%3] == -1) {
			ck[g][(t+1)%3] = ck[q][t] + 1;
			Q.push({g,(t+1)%3});
		} 
	}
	
	if(ck[T][0] == -1){
		out(-1)
	} else {
		out(ck[T][0]/3)
	} 

	return 0;
}