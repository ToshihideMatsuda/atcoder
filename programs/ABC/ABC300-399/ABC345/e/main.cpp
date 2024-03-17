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
	ll N, K; cin >> N >> K;
	vector<ll> C(N), V(N), U(N);
	rep(i,N) {
		cin >> C[i] >> V[i];
	}

	vector<ll> T;
	ll cnt = 1;

	reps(i,1,N) {
		if(C[i-1] == C[i]) {
			cnt++;
		} else {
			cnt = 1;
			T.push_back(cnt);
		}
	}
	T.push_back(cnt);


	vector<ll> nC, nV;

	ll i = 0;
	ll remove = 0;
	for(auto t:T) {
		if(t >1) {
			remove += t-1;
		}
		ll mm = 0;
		rep(j,t) mm = MAX(mm,nV[i+j]); 
		nC.push_back(C[i]);
		nV.push_back(mm);

		i += t;
	}
	if(K < remove) {
		out(-1)
		return 0;
	}

	if(remove == K) {
		ll sum = 0;
		for(auto c : nC) sum += c;
		out(c) 
		return 0;
	} 

	K -= remove;

	while(K > 0) {
		K--;
		
	}



	

	return 0;
}