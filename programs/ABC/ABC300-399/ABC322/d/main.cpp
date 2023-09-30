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
	auto P = vector<vector<vector<vector<bool>>>>(3);

	rep(i,3) {
		
		auto Q = vector(4,vector(4,vector(4,false)));
		ll q  =0;

		rep(h,4)rep(w,4) {
			char p; cin >> p;
			if(p == '#')  {
				Q[0][h][w]     = true;
				Q[1][w][3-h]   = true;
				Q[2][3-h][3-w] = true;
				Q[3][3-w][h]   = true;
				q++;
			}
		}

		for(int ii = -3; ii<= 3; ii++) {
			for(int j = -3; j<= 3; j++) {
				vector<ll> q_n = vector<ll>(4,0);
				auto Q_n = vector(4,vector(4,vector(4,false)));

				reps(h,MAX(0,ii),MIN(4,4+ii)) reps(w,MAX(0,j),MIN(4,4+j))rep(k,4){
					if(Q[k][h][w]) {
						Q_n[k][h-ii][w-j] = true;
						q_n[k] ++;
					}
				} 
				rep(k,4) if(q == q_n[k]) {
					P[i].push_back(Q_n[k]);
				}
			}
		}
	}

	for(auto p : P[0]) for(auto q : P[1]) for(auto r : P[2]) {

		ll cnt = 0;
		rep(h,4)rep(w,4) {
			if( (p[h][w] == true && q[h][w] == true) ||
				(p[h][w] == true && r[h][w] == true) ||
				(r[h][w] == true && q[h][w] == true) || 
				((p[h][w] || q [h][w] || r[h][w])  == false)){
					goto next;
			}
			cnt++;
		}
		if(cnt == 16) {
			out("Yes")
			return 0;
		}

		next: 
			continue;

	}


		out("No")
		return 0;
	
	





	return 0;
}