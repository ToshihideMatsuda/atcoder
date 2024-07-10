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
	ll a, b, c, d, e, f;
	ll g, h, i, j, k, l;
	cin >> a >> b >> c >> d >> e >> f; 
	cin >> g >> h >> i >> j >> k >> l;

	// ll a, b, c, 
	// ll d, e, f;
	// ll g, h, i
	// ll j, k, l;
	vector<tuple<ll,ll,ll>> p = {
		{g,h,i},
		
		{j,h,i},
		{g,h,l},
		{g,k,i},

		{g,k,l},
		{j,h,l},
		{j,k,i},

		{j,k,l},
	};



	for(auto [x,y,z] : p) {
		if(a < x && x < d &&
		   b < y && y < e &&
		   c < z && z < f) {
			out("Yes")
			return 0;
		   }
	}
	{	
		tuple<double,double,double> pp =  {(g+j)/2.0,(h+k)/2.0,(i+l)/2.0};
		auto [x,y,z]  = pp;
		if( a < x && x < d &&
			b < y && y < e &&
			c < z && z < f) {
			out("Yes")
			return 0;
		}
	}

	vector<tuple<ll,ll,ll>> q = {
		{a,b,c},
		
		{a,b,f},
		{a,e,c},
		{d,b,c},

		{a,e,f},
		{d,b,f},
		{d,e,c},

		{d,e,f},
	};
	// ll a, b, c, 
	// ll d, e, f;
	// ll g, h, i
	// ll j, k, l;
	for(auto [x,y,z] : q) {
		if(g < x && x < j &&
		   h < y && y < k &&
		   i < z && z < l) {
			out("Yes")
			return 0;
		}
	}

	{	
		tuple<double,double,double> pp =  {(a+d)/2.0,(b+e)/2.0,(c+f)/2.0};
		auto [x,y,z]  = pp;
		if(g < x && x < j &&
		   h < y && y < k &&
		   i < z && z < l) {
			out("Yes")
			return 0;
		}
	}

	if(a == g && b == h && c ==i && d == j && e == k && f == l) {
		out("Yes")
		return 0;
	}
	out("No")

	return 0;
}