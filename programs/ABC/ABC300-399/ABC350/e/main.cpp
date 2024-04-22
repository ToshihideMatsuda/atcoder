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
#define outd(s) cout << setprecision(20) << s << endl;
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

ll N, A, X, Y; 

double E(ll n);
map<ll, double> memo;
map<ll, double> memoX;
map<ll, double> memoY;
double Ex(ll n) {
	if(n == 0) return 0;
	if(memoX.count(n)) return memoX[n];

	memoX[n] = E(n/A) + X;
	
	return memoX[n];
}

double Ey(ll n) {
	if(n == 0) return 0;
	if(memoY.count(n)) return memoY[n];

	memoY[n] = ( E(n/2) + E(n/3) + E(n/4) + E(n/5) + E(n/6) + 6.0 * Y)/5.0;
	
	return memoY[n];
}

double E(ll n) {
	if(n == 0) return 0;
	if(memo.count(n)) return memo[n];

	memo[n] = MIN(Ex(n), Ey(n));

	return memo[n];
}


int main()
{
	cin >> N >> A >> X >> Y;
	outd(E(N))
	return 0;
}

