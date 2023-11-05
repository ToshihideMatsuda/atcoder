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

set<ll> G[MAX_N] ;
ll H[MAX_N] ;
vector<bool> ch(MAX_N,false);

void dfs( ll p, vector<ll> & path, set<ll> & s) {
	ch[p] = true;
	for(auto g: G[p]) 
		if(ch[g]) {
			if(s.count(g)) {
				ll cnt = 0;
				while(g != path[path.size()-1-cnt]) cnt++;
				cnt++;

				if(cnt %2 == 1) {
					out("No")
					exit(0);
				}
			}
		} else {
			path.push_back(g);
			s.insert(g);

			dfs(g, path,s);

			auto idx = path.end();
			idx--;
			path.erase(idx);
			s.erase(g);
		}
}

int main()
{
	ll N, M; cin >> N >> M;
	vector<ll> A(M), B(M);
	rep(i,M) cin >> A[i];
	rep(i,M) cin >> B[i];

	
	
	rep(i,M) {
		if(A[i] == B[i]) {
			out("No")
			exit(0);
		}
		G[A[i]].insert(B[i]);
		G[B[i]].insert(A[i]);
		H[B[i]]++;
	}

	for(auto p:A) if(H[p] == 0) if(ch[p] == false){
		vector<ll> path = {p};
		set<ll> s = {p};
		dfs(p, path,s);
	}

	reps(p,1,N+1) if(ch[p] == false){
		vector<ll> path = {p};
		set<ll> s = {p};
		dfs(p, path,s);
	}
	
	out("Yes")
	exit(0);
	

	return 0;
}