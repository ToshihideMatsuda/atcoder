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


#define INF  (2000000000000000001LL)
#define MINF (-2000000000000000001LL)
#define MOD 998244353

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


int main()
{
	ll N; cin >> N;
	readG(N-1);

	ll ans = 0;

	vector<ll> Two;
	set<ll> Two2Three;

	for(int q = 1; q <= N; q++) if(ck[q] == false) {

		queue<ll> Q;
		Q.push(q);
		ll cnt = 0;
		while(Q.size() > 0)  {
			ll t = Q.front(); Q.pop();
			ck[t] = true;
			if( G[t].size() == 2) {
				Two.push_back(t);
				if(G[G[t][0]].size() == 3 || G[G[t][1]].size() == 3) Two2Three.insert(t);
				cnt++;
				for(auto g:G[t]) if(ck[g] == false) {
					Q.push(g);
				}
			}
		}

		if(cnt > 0) {
			//ans += cnt-1;
		}
	}

	rep(i,MAX_N) ck[i] = false; 
	for(auto t:Two2Three) if(ck[t] == false) {
		queue<ll> Q;
		if(G[G[t][0]].size() == 3 && ck[G[t][0]] == false) Q.push(G[t][0]);
		if(G[G[t][1]].size() == 3 && ck[G[t][1]] == false) Q.push(G[t][1]);

		ll tmp = 1;
		while(Q.size() > 0) {
			auto q = Q.front();Q.pop();
			ck[q] = true;
			for(auto g:G[q]) {
				if(g != t && G[g].size() == 2) {
					tmp++;
					ck[g] = true;
				} else if(ck[g] == false && G[g].size() == 3) {
					Q.push(g);
				} else {
					ck[g] = true;
				}
			}
		}
		ans += tmp*(tmp-1)/2;
	}

	out(ans)

	return 0;
}