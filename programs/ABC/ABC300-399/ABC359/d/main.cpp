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

int main()
{
	ll N, K; cin >> N >> K;
	string S; cin >> S;

	set<ll> kaibun;
	for(int i = 0; i < (1 << K); i ++) {
		vector<bool> b(K,false);
		rep(j,K) if(0 < ((1 << j) & i)) b[j] = true;

		bool ok = true;
		rep(i,K) if(b[i] != b[K-1-i])  {
			ok = false;
			break;
		}

		if(ok) kaibun.insert(i);
	}

	mint zero = 0;
	vector dp = vector(N+1,vector<mint>(1 << K, zero));

	queue<ll>Q;
	Q.push(0);
	rep(i,K) {
		queue<ll> Q2;
		vector<ll> add;
		if(S[i] == 'A') {
			add = { 0 };
		} else if(S[i] == 'B') {
			add = { 1 };
		} else {
			add = { 0, 1};
		}
		while(Q.size() > 0) {
			auto q = Q.front();Q.pop();
			for(auto a : add) {
				Q2.push( (q << 1) + a );
			}
		}
		Q = std::move(Q2);
	}

	while(Q.size() > 0) {
		auto q = Q.front();Q.pop();
		if(kaibun.count(q) == false) dp[K-1][q] = 1;
	}

	reps(k,K,N) {
		vector<ll> add;
		if(S[k] == 'A') {
			add = { 0 };
		} else if(S[k] == 'B') {
			add = { 1 };
		} else {
			add = { 0, 1};
		}

		for(int i = 0; i < (1 << K); i ++) {
			int j = (i << 1) & ( ~ (1 << K) ) ; // K bit目は0
			
			for(auto a : add) {
				if(kaibun.count(j+a) == false) {
					dp[k][j+a] += dp[k-1][i];
				}
			}
		}
	}

	mint ans =0;
	for(int i = 0; i < (1 << K); i ++) ans +=  dp[N-1][i];
	out(ans.val())


	


	return 0;
}