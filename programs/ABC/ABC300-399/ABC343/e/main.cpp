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

int main()
{
	ll v[3]; cin >> v[0] >> v[1] >> v[2];

	for(int a2 = -7; a2 < 8; a2++) {
	for(int b2 = -7; b2 < 8; b2++) {
	for(int c2 = -7; c2 < 8; c2++) {
		for(int a3 = -7; a3 < 8; a3++) {
		for(int b3 = -7; b3 < 8; b3++) {
		for(int c3 = -7; c3 < 8; c3++) { // 2^18 = 2.5 * 10^5

			ll w[3]; rep(i,3) w[i] = 0;
			
			ll A3 = MAX(0,MIN3(7,a2+7,a3+7) - MAX3(0,a2,a3));
			ll B3 = MAX(0,MIN3(7,b2+7,b3+7) - MAX3(0,b2,b3));
			ll C3 = MAX(0,MIN3(7,c2+7,c3+7) - MAX3(0,c2,c3));
			w[2] = A3 * B3 * C3;

			
			ll A2_1 = MAX(0,MIN(7,a2+7) - MAX(0,a2));
			ll B2_1 = MAX(0,MIN(7,b2+7) - MAX(0,b2));
			ll C2_1 = MAX(0,MIN(7,c2+7) - MAX(0,c2));

			ll A2_2 = MAX(0,MIN(7,a3+7) - MAX(0,a3));
			ll B2_2 = MAX(0,MIN(7,b3+7) - MAX(0,b3));
			ll C2_2 = MAX(0,MIN(7,c3+7) - MAX(0,c3));

			ll A2_3 = MAX(0,MIN(a3+7,a2+7) - MAX(a3,a2));
			ll B2_3 = MAX(0,MIN(b3+7,b2+7) - MAX(b3,b2));
			ll C2_3 = MAX(0,MIN(c3+7,c2+7) - MAX(c3,c2));
			w[1] = A2_1 * B2_1 * C2_1 + A2_2 * B2_2 * C2_2 + A2_3 * B2_3 * C2_3 - 3 * w[2];

			w[0]= 7*7*7*3 - (w[1]*2 + w[2]*3); 


			if(
				v[0] == w[0] &&
				v[1] == w[1] &&
				v[2] == w[2] 
			) {
				out("Yes")
				vector<ll> X = {0,0,0,a2,b2,c2,a3,b3,c3};
				OUT(X," ") //9 7 7 4 4 3 1
				return 0;
			}
			
		}
	}
	}
	}
	}
	}

	out("No")
	return 0;
}