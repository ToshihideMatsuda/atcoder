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

vector<ll> A(MAX_N); 
vector<ll> H(MAX_N);
ll N; 


vector<ll> cnt(MAX_N,0);

void circle(ll u) {
	ll w = u;
	ll c = 1;
	while(A[w] != u) {
		w = A[w];
		c++;
	}
	w = u;
	cnt[w] = c;
	while(A[w] != u) {
		w = A[w];
		cnt[w] = c;
	}
}

void dfs(int v, set<int> & s ) {
	if(cnt[v] > 0) return;
    s.insert(v);

    int u = A[v];
	if(s.count(u)) {
		circle(u);
		return;
	} else {   
		dfs(u, s);
		if(cnt[v] > 0) return;
		cnt[v] = cnt[u]+1;
	}
    
}


int main()
{
	cin >> N;
	reps(i,1,N+1) {
		cin >> A[i];
		H[a]++;
	}

	reps(i,1,N+1) if(H[i] == 0) {
		set<int> component ;
		dfs(i, component);
	}
	reps(i,1,N+1) if(cnt[i] == 0 && A[i] != 0) circle(i);

	ll sum = 0;
	reps(i,1,1+N) sum += cnt[i];
	out(sum)

	return 0;
}