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

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


//入力値cに対する素因数分解の関数。cとしては <= 10^12を想定。
//またエラトステネスの篩によって素数が計算されている前提
bool prime[1000000+9]; //エラトステネスの篩で計算
unordered_map<ll,ll> factorial(ll c) {
	// 素因数分解結果
	unordered_map<ll,ll> factor;
	for(ll i = 2; i < 1000000+9; i ++) {
		if(prime[i]){
			while( c % i == 0) {
				factor[i] ++;
				c /= i;
			}
		}
	}
	if(c > 1) factor[c] ++;
    return factor;
}

//エラトステネスの篩、prime[i] = true -> 素数
void EratosthenesPrime(ll N){
  if(N == -1) N = 1000000+5;
  rep(i,1000000+9) prime[i] = true;
  prime[0] = false;
  prime[1] = false;
	for(ll i= 2; i<N+1;i++){
		for(ll j=2*i;j<N+1;j +=i){
			prime[j] =false;
		}
	}
}

using mint = modint998244353;


int main()
{
	ll A, BB; cin >> A >> BB;
	bll B = BB;
	EratosthenesPrime(-1);
	auto f = factorial(A);

	vector<bll> vec;
	for(auto idx = f.begin(); idx != f.end(); ++ idx) {
		vec.push_back((*idx).second);
	}
	
	bll all = 1; 
	rep(i,vec.size()) {
		bll P = vec[i];
		all *= (P * B + 1);
	}

	bll ans = 1;
	rep(i,800) ans *= 2;
	rep(i,vec.size()) {
		bll P = vec[i];
		bll val =  ( all / (P * B + 1) ) *  ( (P * B) * (P * B + 1) / 2 ) /  P ;
		if(val < ans) {
			ans = val;
		}
	}

	ans %= MOD;
	
	out(ans)


	return 0;
}