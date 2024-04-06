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

#define MAX_N (100000+5)
ll N;
vector<ll> G[MAX_N];
ll C[MAX_N];

bool ck[MAX_N]; 
void clear() { rep(i,MAX_N) ck[i] = false; }

ll R2SUM[MAX_N];
ll CSUM[MAX_N];

ll parent[MAX_N];
ll parentSUM[MAX_N];

ll dfs(ll p) {
	ck[p] = true;
	ll sum = C[p];
	for(auto g:G[p]) if(ck[g] == false) {
		parent[g] = p;
		sum += dfs(g);
	}

	R2SUM[p] = sum;
	return sum;
}


int main()
{
	cin >> N;
	rep(i,N-1) {
		ll A, B; cin >> A >> B;
		G[A].push_back(B);
		G[B].push_back(A);
	}
	reps(i,1,N+1) cin >> C[i];

	clear(); dfs(1);

	reps(i,1,N+1) {
		for(auto gg:G[i]) CSUM[i]  += R2SUM[gg];
	}
	reps(i,1,N+1) parentSUM[i] = CSUM[1] + C[1] - R2SUM[i];

	ll f = 0;
	{
	queue<pair<ll,ll>> Q;
	clear();
	Q.push({1,0});
	ck[1] = true;
	
	while(Q.size() > 0) {
		auto [q,t] = Q.front(); Q.pop();
		for(auto g:G[q]) if(ck[g] == false){
			ck[g] = true;
			f += C[g] * (t+1);
			Q.push({g,t+1});
		}
	}
	}

	ll ans = f;

	queue<pair<ll,ll>> Q;
	clear();
	Q.push({1,f});
	ck[1] = true;

	while(Q.size() > 0) {
		auto [q,f] = Q.front(); Q.pop();
		for(auto g:G[q]) if(ck[g] == false){
			ck[g] = true;

			ll ff = f - (C[g] + ( CSUM[g] - R2SUM[q]) ) 
					  +	(C[q] + ( CSUM[q] - R2SUM[g] - ( R2SUM[parent[q]] -  parentSUM[q])));

			ans = MIN(ans,ff);

			Q.push({g,ff});
		}
	}

	out(ans)


	return 0;
}