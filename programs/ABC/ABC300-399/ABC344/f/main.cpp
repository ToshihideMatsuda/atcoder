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
	ll N; cin >> N;
	vector P = vector(N+1,vector(N+1,0));
	vector R = vector(N+1,vector(N+1,0));
	vector D = vector(N+1,vector(N+1,0));
	rep(i,N)  rep(j,N)   cin >> P[i+1][j+1];
	rep(i,N)  rep(j,N-1) cin >> R[i+1][j+1];
	rep(i,N-1)rep(j,N)   cin >> D[i+1][j+1];

	set<ll> Pset;
	reps(i, 1, N+1)reps(j,1,N+1) Pset.insert(P[i][j]);
	vector<ll> Pvec;
	map<ll,ll> Prev; 
	ll idx = 0;
	for(auto p:Pset) {
		Pvec.push_back(p);
		Prev[p] = idx++;
	}

	pair<ll,ll> dp[N+1][N+1][Pvec.size()];

	reps(h,1,N+1)reps(w,1,N+1) rep(k,Pvec.size()) {
		dp[h][w][k] = {INF_LL,INF_LL};
	}

	dp[1][1][Prev[P[1][1]]] = {0, 0}; 
	reps(h,1,N+1)reps(w,1,N+1) {
		
		rep(k,Pvec.size()) if(dp[h][w][k].first < INF_LL) {
			auto [cnt, m_money] = dp[h][w][k];
			auto p = Pvec[k];
			ll money = - (m_money);

			//right
			if(w < N) {

				ll l = 0;
				if(Pvec[k] < P[h][w+1]) {
					l = Prev[P[h][w+1]];
				} else {
					l = k;
				}

				if(R[h][w] <= money) {
					dp[h][w+1][l] = min(dp[h][w+1][l],{cnt+1,-(money-R[h][w])});
				} else {
					ll r = (R[h][w] - money) % p;
					ll q = (R[h][w] - money) / p;
					if(r > 0) {
						q++;
						r = p - r;
					}
					dp[h][w+1][l] = min(dp[h][w+1][l], {cnt+q+1,-r} );
				}
			}

			//down
			if(h < N) {

				ll l = 0;
				if(Pvec[k] < P[h+1][w]) {
					l = Prev[P[h+1][w]];
				} else {
					l = k;
				}

				if(D[h][w] <= money) {
					dp[h+1][w][l] = min(dp[h+1][w][l], {cnt+1,-(money-D[h][w])});
				} else {
					ll r = (D[h][w] - money) % p;
					ll q = (D[h][w] - money) / p;
					if(r > 0) {
						q++;
						r = p - r;
					}

					dp[h+1][w][l] = min(dp[h+1][w][l], {cnt+q+1,-r});
				}
			}
		}
	}


	ll ans = INF_LL;

	rep(k,Pvec.size()) {
		ans = MIN(ans,dp[N][N][k].first);
	}

	out(ans)

	return 0;
}