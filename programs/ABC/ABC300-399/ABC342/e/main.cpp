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

int main()
{
	ll N, M; cin >> N >> M;
	vector<tuple<ll,ll,ll,ll,ll>> G[MAX_N];
	vector<ll> l(M), d(M), k(M), c(M); 
	rep(i,M) {
		ll L,D,K,C,A, B;
		cin >> L >> D >> K >> C >> A >> B;
		G[B].push_back({A, L, D, K, C});
	}

	vector<ll> dp(N+1,-1);
	dp[N] = INF_LL;
	priority_queue<pair<ll,ll>> Q; 
	Q.push({INF_LL,N});

	while(Q.size() > 0) {
		auto [_,b]= Q.top(); Q.pop();
		for(auto [a, L, D, K, C] : G[b]) {

			ll lb = 0, ub = K;
			while(ub - lb > 1) {
				ll mid = (lb+ub)/2;
				if(L+mid*D+C<= dp[b]) {
					lb = mid;
				} else {
					ub = mid;
				}
			}

			if(L+lb*D+C<= dp[b] && dp[a] < L+lb*D) {
				dp[a] = L+lb*D;
				Q.push({dp[a],a});
			}
		}
	}

	reps(i,1,N) {
		if(dp[i] == -1) {
			out("Unreachable")
		} else { 
			out(dp[i])
		}
	}



	return 0;
}