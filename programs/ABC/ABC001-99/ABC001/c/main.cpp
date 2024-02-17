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
	ll des,dis; cin >> des >> dis;

	vector<string> list = {
			 "NNE", "NE", "ENE", "E", "ESE", "SE", "SSE", 
		"S", "SSW", "SW", "WSW", "W", "WNW", "NW", "NNW"
	};

	des *= 10;
	string dir = "N";
	rep(i,list.size()) {
		if(1125 + 2250*i <= des && des < 3375 + 2250*i) {
			dir = list[i];
			break;
		}
	}

	ll w10 = (ll)(dis*5/3);
	ll w = w10/10 + ((5<= w10%10) ? 1 : 0 ) ;

	ll W = 0;
	if(w <= 2) W = 0;
	else if(w <= 15) W = 1;
	else if(w <= 33) W = 2;
	else if(w <= 54) W = 3;
	else if(w <= 79) W = 4;
	else if(w <= 107) W = 5;
	else if(w <= 138) W = 6;
	else if(w <= 171) W = 7;
	else if(w <= 207) W = 8;
	else if(w <= 244) W = 9;
	else if(w <= 284) W = 10;
	else if(w <= 326) W = 11;
	else W = 12;
	if(W == 0) dir = "C";
	out0(dir) out0(" ") out(W)
	
	return 0;
}