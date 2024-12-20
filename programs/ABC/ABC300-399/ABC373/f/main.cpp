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
#define MINF_LL (-9223372036775808LL)
#define MOD 998244353

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


int main()
{
	ll N, W; cin >> N >> W;
	vector<vector<pair<ll,ll>>> wv2;
	rep(i,N) {
		ll w,v; cin >> w >>v;
		vector<pair<ll,ll>> wv;
		ll k = 1;
		ll d = 0;
		while(k*w <= W){
			if(d <= k*v-k*k) {
			wv.push_back({k*w, k*v-k*k});
			k++;
			d = k*v-k*k;
			} else {
				break;
			}
		}
		wv2.push_back(wv);
	}

	vector<ll> dp(W+5, MINF_LL);
	dp[0] = 0;

	for(auto wv : wv2) {
		vector<ll> dp2(dp);
		reps(i,1,W+1){
			for(auto [w,v]:wv) if(0 <= dp[i-w]){
				if(0<=i-w) dp2[i] = MAX(dp2[i],dp[i-w]+v);
			}
		}
		dp = move(dp2);
	}

	ll ans = 0;
	reps(i,1,W+1 ) ans = MAX(ans, dp[i]);
	out(ans)



	return 0;
}