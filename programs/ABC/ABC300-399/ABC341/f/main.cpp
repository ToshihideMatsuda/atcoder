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

#define MAX_N (5000+5)

int main()
{
	ll N, M ; cin >> N >> M;
	vector<ll> G[MAX_N];
	rep(i,M) {
		ll u, v; cin >> u >> v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	
	vector<ll> W(N+1), A(N+1);
	rep(i,N) cin >> W[i+1];
	rep(i,N) cin >> A[i+1];

	ll cnt = 0;
	vector<ll> benefit(N+1,-1);
	while(cnt < N) {
		reps(p,1,N+1) if(benefit[p] == -1){
			ll known = true;
			for(auto g:G[p]) {
				if(W[p] <= W[g]) continue;
				if(W[g] < W[p] && benefit[g] == -1) {
					known = false;
					break;
				}
			}

			if(known) {
				cnt ++;
				vector<ll> dp(W[p], -1);
				dp[0] = 0;
				for(auto g:G[p]) if(W[g] < W[p]) {
					for(int i = W[p] - 1; i > -1; i --) if(0 <= dp[i] && i+W[g] < W[p]) {
						dp[i+W[g]] = MAX(dp[i+W[g]], dp[i] + benefit[g]);
					} 
				}
				rep(i,W[p]) benefit[p] = MAX(benefit[p], dp[i]);
				benefit[p]+=1;
			}
		}
	}

	ll ans = 0;
	reps(i,1,N+1) ans += A[i] * benefit[i]; 
	out(ans)
	return 0;
}