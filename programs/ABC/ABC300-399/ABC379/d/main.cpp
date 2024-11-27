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


#define INF  (2000000000000000001LL)
#define MINF (-2000000000000000001LL)
#define MOD 998244353

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


int main()
{
	ll Q; cin >> Q;

	vector<tuple<ll,ll,ll>> V;
	while(Q--) {
		ll t; cin >> t;
		if(t == 1) {
			if(V.size() > 0) {
				auto [tt,c,h]= V.back();
				if(tt == 1 && h == 0) {
					V[V.size()-1] = {1, c+1, 0};
					continue;
				}
			}

			V.push_back ({1, 1, 0});
		} else if (t == 2) {
			ll T; cin >> T;
			V.push_back({2,T, -1});
		} else if (t == 3) {
			ll H; cin >> H;
			ll tmp = 0;
			
			ll ans = 0;
			vector<tuple<ll,ll,ll>> VV;
			for(int i = V.size() -1 ; i > -1; i --) {
				auto [tt,c,h]= V[i];
				if(tt == 1) {
					if(H <= tmp + h) {
						//収穫
						ans += c;
					} else {
						VV.push_back({1,c,tmp+h});
					}
				} else {
					tmp += c;
				}
			}

			out(ans)

			V = move(VV);

		}
	}
	return 0;
}