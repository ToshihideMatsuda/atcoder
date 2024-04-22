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
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


int main()
{
	ll K; cin >> K;
	vector<ll> A(K);
	rep(i,K) cin >> A[i];

	ll l, h;
	if(A.back() == 1) {
		l = 2;
		h = 2;
	} else if (A.back() == 2) {
		l = 2;
		h = 3;
	} else {
		out(-1)
		return 0;
	}

	for(int k = K-2; k >= 0; k--) {
		ll ok = MAX( (l/A[k] + ((l%A[k] == 0) ? 0 : 1) )*A[k]  , A[k]);
		if(ok < l || h < ok) {
			out(-1)
			return 0;
		}

		ll lb = 0, ub = ok;
		while(ub - lb > 1) {
			ll mid = (ub + lb) / 2;
			
			ll t = (mid/ A[k]) * A[k];

			if(l <= t){
				ub = mid;
			} else {
				lb = mid;
			}
		}

		ll next_l = ub;

		lb = ok, ub = INF_LL >> 2;
		while(ub - lb > 1) {
			ll mid = (ub + lb) / 2;
			
			ll t = (mid / A[k]) * A[k];

			if(t <= h){
				lb = mid;
			} else {
				ub = mid;
			}
		}
		l = next_l;
		h = lb;
	}

	out0(l) out0(" ") out0(h)

	return 0;
}