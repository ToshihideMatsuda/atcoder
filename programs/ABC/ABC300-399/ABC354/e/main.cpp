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


ll N;
vector<ll> A, B;

ll memo[2][(1 << 18) + 5];

bool winT(ll turnOfT, ll chosen) {
	if(memo[turnOfT][chosen] != -1) {
		return memo[turnOfT][chosen];
	}

	rep(i,N-1) reps(j,i+1,N) {
		if((chosen & (1 << i) ) == 0) 
		if((chosen & (1 << j) ) == 0) 
		if(A[i] == A[j] || B[i] == B[j]) {
			bool result = winT(1 - turnOfT, chosen | (1 << i) | (1 << j) );
			if(result == turnOfT) {
				memo[turnOfT][chosen] = turnOfT;
				return turnOfT;
			}
		}
	}

	memo[turnOfT][chosen] = 1 - turnOfT;
	return 1 - turnOfT;
}

int main()
{
	cin >> N;
	A.resize(N), B.resize(N);
	rep(i,N) cin >> A[i] >> B[i];

	rep(i,2)rep(j,(1 << 18) + 5) memo[i][j] = -1;


	ll isTakahashi = winT(1,0);

	if(isTakahashi == 1) {
		out("Takahashi")
	} else {
		out("Aoki")
	}


	return 0;
}