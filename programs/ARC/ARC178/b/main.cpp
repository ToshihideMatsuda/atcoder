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

using mint = modint998244353;


// 冪乗計算 (x^n) % mod の計算
// mod <= 0 の場合には通常の冪乗計算（オーバーフロー無視）
ll pow(ll x, ll n, ll mod) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1) {  // n の最下位bitが 1
            ret *=x;  // n の最下位bitが 1 ならば x^(2^i) をかける
            if(mod > 0) ret %=mod;
        }
        x *= x;       // nのビット数分だけ累乗する
        x %= mod;
        n >>= 1;      // n を1bit 左にずらして次のビットを見る
    }
    return ret;       // ret = ( x^n )% mod 
                      //     = (x^(10110...1)_2 % mod )みたいなイメージで計算していく
}



int main()
{
	
	ll cnt = 0;
	ll carry = 0;
	reps(i,10,100)reps(j,100,1000)if(i+j<= 999) cnt++; else {
		carry ++;
		//cout << i << "," << j << endl;;
	}
	

	ll T; cin >> T;
	while(T--) {
		ll a1, a2, a3; cin >> a1 >> a2 >> a3;

		ll t1 = a1, t2 = a2;
		a1 = MIN(t1,t2); a2 = MAX(t1,t2);
		
		mint curryover = 0;
		
		if(a1 == a2) {
			mint nineP = 1, ten = pow(10,a1-1,MOD);
			nineP = 9*ten;
			curryover = (nineP + ten) * (nineP - ten + 1) / 2 + (ten - 1) * nineP;

		} else if(a1 < a2) {
			mint nine = pow(10,a1,MOD), ten = pow(10,a1-1,MOD);
			nine--;
			curryover = (nine + ten) * (nine - ten + 1) / 2 ;
		}

		if(a2 == a3) {
			//繰り上がらない場合
			mint A1 = pow(10,a1-1,MOD);
			A1 *= 9; 

			mint A2 = pow(10,a2-1,MOD);
			A2 *= 9; 

			mint ans = A1 * A2 - curryover;

			out(ans.val())
		} else if( a2+1 == a3 ) {
			out(curryover.val())
		} else {
			out(0)
		}
	}
	return 0;
}