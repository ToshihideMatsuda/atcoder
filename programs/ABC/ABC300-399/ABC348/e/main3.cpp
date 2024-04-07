/* 全方位木DP(rerooting)による解法 */

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

#define MAX_N (100000+5)
ll N;
vector<ll> G[MAX_N];
ll C[MAX_N];

bool ck[MAX_N]; 
void clear() { rep(i,MAX_N) ck[i] = false; }

ll sum_c[MAX_N];
ll sub_f[MAX_N];
ll f[MAX_N];

void dfs(ll p) {
	ck[p] = true;
	sum_c[p] = C[p];
	sub_f[0] = 0;
	for(auto g:G[p]) if(ck[g] == false){
		ck[g] = true;
		dfs(g);

		sum_c[p] += sum_c[g];	
		sub_f[p] += (sub_f[g] + sum_c[g]);
	}
}

void rerooting(ll p, ll other_sum_c, ll other_f) {
	ck[p] = true;
	f[p] = sub_f[p] + other_f;

	for(auto g:G[p]) if(ck[g] == false){
		ck[g] = true;
		ll next_other_sum_c = other_sum_c + (sum_c[p] - sum_c[g]);
		ll next_other_sum_f = (other_f + other_sum_c) 
								+ (sub_f[p] -(sub_f[g] + sum_c[g]))
								+ (sum_c[p] - sum_c[g]); 
		rerooting(g, next_other_sum_c, next_other_sum_f);
	}
}

int main()
{
	cin >> N;
	rep(i,N-1) {
		ll A, B; cin >> A >> B;
		G[A].push_back(B);
		G[B].push_back(A);
	}
	reps(i,1,N+1) cin >> C[i];

	clear(); dfs(1);
	clear(); rerooting(1,0,0);

	ll ans = INF_LL;
	reps(i,1,N+1) ans = MIN(ans,f[i]);
	out(ans)


	return 0;
}