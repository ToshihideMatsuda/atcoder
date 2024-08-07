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



vector A = vector(3,vector(3,0LL));

ll dfs(ll turn,ll takahashi, ll aoki, vector<vector<ll>>& used, set<pair<ll,ll>>& aki) {
	
	if(aki.size() == 0) {
		if(aoki < takahashi) {
			return 1;
		} else {
			return	-1;
		}
	}

	auto aki2 = aki;
	for(auto [i,j]:aki) {
		used[i][j] = turn;
		if(
			(used[i][0] == turn && used[i][1] == turn && used[i][2] == turn) || 
			(used[0][j] == turn && used[1][j] == turn && used[2][j] == turn) ||
			(used[0][0] == turn && used[1][1] == turn && used[2][2] == turn) ||
			(used[2][0] == turn && used[1][1] == turn && used[0][2] == turn) 
		){
			used[i][j] = 0;
			return turn;
		}
	
		if(turn == 1) {
			takahashi += A[i][j];
		} else {
			aoki += A[i][j];
		}

		aki2.erase({i,j});
		ll win = dfs(turn * -1,takahashi, aoki, used, aki2) ;
		aki2.insert({i,j});
		used[i][j] = 0;
		if(turn == 1) {
			takahashi -= A[i][j];
		} else {
			aoki -= A[i][j];
		}

		if(win == turn) {
			return turn;
		}

	}

	return turn * -1;


}




int main()
{
	rep(i,3)rep(j,3) cin >> A[i][j];

	vector used = vector(3,vector(3,0LL));	
	set<pair<ll,ll>> aki;
	rep(i,3) rep(j,3) aki.insert({i,j});
	ll win = dfs(1,0,0,used, aki);

	if(win == 1) {
		out("Takahashi")
	} else {
		out("Aoki")
	}
	

	return 0;
}