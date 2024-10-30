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


int main()
{
	ll N, M, K; cin >> N >> M >> K;
	vector<ll> A(N), sA(N);
	ll S = 0;
	rep(i,N) {
		cin >> A[i];
		S += A[i];
		sA[i] = A[i];
	}

if(N == M) {
	rep(i,N) out(0)
	return 0;
}
	sort(sA.begin(),sA.end());
	sA.push_back(INF_LL);

	vector<ll> SA(N+1);
	SA[0] = 0;
	rep(i,N)SA[i+1] = SA[i] + sA[i];

	ll R = K-S;

	rep(i,N) {
		ll max = A[i] + R;
		auto idx = lower_bound(sA.begin(),sA.end(),max+1);
		ll d = distance(sA.begin(),idx);
		ll m = N - d;
		if(M <= m) {
			out0(-1);
			out0(" ")
			continue;
		}


		ll lb = -1,  ub = R;
		while(ub-lb > 1) {
			ll mid = (lb + ub)/2;
			auto idx = lower_bound(sA.begin(),sA.end(),A[i]+mid+1);
			ll d = distance(sA.begin(),idx);
			ll m = N - d;
			if(M <= m) {
				lb = mid;
				continue;
			}

			ll k = M - m;

			ll sum = 0;
			// sA[d-k] ~ sA[d-1]
			if(0 <= d-k &&  sA[d-k] <= A[i] && A[i] <= sA[d-1]) {
				if(d-k-1 < 0) {
					sum = SA[d] - A[i];
				} else {
					sum = SA[d] - SA[d-k-1] - A[i];
				}
			} else {
				if(d-k <0) {
					sum = SA[d];
				} else {
				// sA[d-k] ~ sA[d-1]
					sum = SA[d] - SA[d-k];
				}
			}

			if((A[i]+mid+1)*k <= sum + (R-mid) ) {
				lb = mid;
			} else {
				ub = mid;
			}
		}
		out0(ub)
		out0(" ")

	}



	return 0;
}