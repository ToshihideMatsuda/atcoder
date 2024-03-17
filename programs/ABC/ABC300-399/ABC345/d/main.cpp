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
	ll N, H, W; cin >> N >> H >> W;
	vector<ll> A(N), B(N);
	rep(i,N) {
		cin >> A[i] >> B[i];
	}

	vector<vector<ll>> n;
	rep(i,N) {
		if(n.size() == 0) {
			rep(j,3) {
				n.push_back({j});
			}
			continue;
		}
		vector<vector<ll>> nn;
		for(auto m : n){
			rep(j,3) {
				vector<ll> mm(m);
				mm.push_back(j);
				nn.push_back(mm);
			}
		}

		n = move(nn);
	}



	for(auto nn: n) {

		vector<ll> P;
		rep(i,N) P.push_back(i);

		do {

			vector<ll> List(W);

			for(int k = 0; k < P.size(); k++ ) {

				auto p = P[k];
				ll a = A[p];
				ll b = B[p];
				if(nn[k] == 0) continue;
				else if(nn[k] == 1) swap(a,b);


				ll mm = INF_LL;
				ll idx = 0;
				ll cur = 0;
				ll len = 0;
				rep(i,W) {
					if(List[i] < mm) {
						if(cur != List[i]) {
							len  = 1;
							cur = List[i];
						} else if(cur == List[i]) {
							len ++;
						}
						if(b <= len) {
							mm = List[i]; 
							idx = i-(len-1);
						}
					}
				}

				if(mm == INF_LL) {
					goto next;
				}

				rep(i, b) {
					List[idx+i] += a;
				}
			}

			rep(i,W) if(List[i] != H) goto next;
			out("Yes")
			return 0;


			next:
			continue;
		} while (next_permutation(P.begin(), P.end()));
	}

	out("No")
	
	return 0;
}