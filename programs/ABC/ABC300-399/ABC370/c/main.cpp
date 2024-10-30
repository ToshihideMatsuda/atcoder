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
set<ll> G[9], H[9];


int main()
{
	ll N; cin >> N;
	ll Mg, Mh; cin >> Mg;
	rep(i,Mg) {
		ll u,v;
		cin >>  u >> v;
		G[u].insert(v);
		G[v].insert(u);
	}
	cin >> Mh;

	rep(i,Mh) {
		ll u,v;
		cin >>  u >> v;
		H[u].insert(v);
		H[v].insert(u);
	}

	vector A = vector(N+1,vector<ll>(N+1));
	reps(i,1,N){
		for(int j=i+1; j <= N; j ++) {
			cin >> A[i][j];
			A[j][i] = A[i][j];
		}
	}


	ll ans = INF_LL;
	vector<ll> P;
	reps(i,1,N+1)P.push_back(i);
	do {
		set<ll> GP[9];
		reps(i,1,N+1) {
			for(auto g : G[i]) {
				GP[P[i-1]].insert(P[g-1]);
			}
		}

		ll t = 0;
		reps(i,1,N+1) {
			reps(j,1,N+1) if(GP[i].count(j) != H[i].count(j)){
				t += A[MIN(i,j)][MAX(i,j)];
			}
		}

		ans = MIN(ans,t/2);



	}while(next_permutation(P.begin(),P.end()));

	out(ans)



	return 0;
}