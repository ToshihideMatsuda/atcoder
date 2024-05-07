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

using mint = modint1000000007;

long long const SIZE = (2*100000+5);

vector<mint> fact, fact_inv, inv;
/*  init_nCk :二項係数のための前処理
    計算量:O(n)
*/
bool init = false;
void initFact() {
    if(init) return ;
    fact.resize(SIZE + 5);

    fact[0] = fact[1] = 1;

    for (int i = 2; i < SIZE + 5; i++) {
        fact[i] = fact[i - 1] * i;
    }
    init = true;
}

mint modPerm(ll n, ll k) {
    initFact();
    return (fact[n] / fact[n-k]);
}

mint modComb(ll n, ll k) {
    initFact();
    if(k==0) return 1;
    mint a = modPerm(n, k);
    return (a / fact[k]);
}

mint modHomo(ll n, ll k) {
    initFact();
    return modComb(n+k-1,k);
}

int main()
{
	ll N, K; cin >> N >> K;

	for(int i = 1; i <= K; i ++ ) {
		if(N-K+1 < i) {
			out(0)
			continue;	
		} else if(K < i) {
			out(0)
			continue;
		}

		mint v = modComb(N-K+1,i);
		mint u = modHomo(i, K-i);
		out((v*u).val());
	}

	return 0;
}