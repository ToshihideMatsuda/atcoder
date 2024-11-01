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
#define OUT(A,separate)for(auto a : A) { cout << a << separate; } 


#define INF (2147483647)
#define MINF (-2147483648)
#define INF_LL  (9223372036854775807LL)
#define MINF_LL (-9223372036854775807LL)
#define MOD 998244353

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

// x,y
// y,N−x
// N-x,N-y
// N-y,x

// x,y//

int main()
{
	ll N; cin >> N;
	vector A = vector<string>(N);
	vector B = vector<string>(N);
	vector C = vector(N+2,vector<ll>(N+2,-1));
	rep(i,N+2) {
		C[i][0] = -2;
		C[i][N+1] = -2;
	} 
	rep(j,N+2){
		C[0][j] = -2;
		C[N+1][j] = -2;
	}

	string S = "";
	rep(i,N) S += "-";
	rep(i,N){
		cin >> A[i];
		B[i] = S;
	}

	vector<pair<ll,ll>> d = {
		{0,1},{1,0},{0,-1},{-1,0}
	};

	reps(i,1,N+1)if(C[i][i] == -1){
		ll x = i, y = i;
		ll j = 0;
		do {
			ll px = x-1, py = y-1;
			if((i % 4) == 0) {
				B[px][py] = A[px][py];
			} else if( (i%4) == 1){
				B[py][N-1-px] = A[px][py];
			} else if( (i%4) == 2 ) {
				B[N-1-px][N-1-py] = A[px][py];
			} else {
				B[N-1-py][px] = A[px][py];
			}
			

			C[x][y] = (i % 4);
			auto[dx,dy] = d[j];
			if(C[x+dx][y+dy] == -1) {
				x += dx;
				y += dy;
			} else if(j < 3) {
				j++;
			} else {
				break;
			}

		} while(true);
	}

	OUT(B,endl)




	return 0;
}