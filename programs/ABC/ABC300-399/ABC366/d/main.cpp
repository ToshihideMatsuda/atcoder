#include <bits/stdc++.h> 
#include <atcoder/all>

using namespace atcoder;
using namespace std;
// 多倍長テンプレ（デバッグだとダメかも）

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
#define MINF_LL (-9223372036854775807LL)
#define MOD 998244353

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


int main()
{
	ll N; cin >> N;
	vector A = vector(N+1,vector(N+1,vector(N+1, 0LL) ));
	vector S = vector(N+1,vector(N+1,vector(N+1, 0LL) ));

	rep(i,N)rep(j,N)rep(k,N) cin >> A[i+1][j+1][k+1];
	rep(i,N)rep(j,N)rep(k,N) {
		S[i+1][j+1][k+1] = A[i+1][j+1][k+1] + 
								( S[i][j+1][k+1] + S[i+1][j][k+1] + S[i+1][j+1][k] )
								- ( S[i][j][k+1] + S[i][j+1][k]   + S[i+1][j][k])
								+ S[i][j][k];
	}


	ll Q; cin >> Q;

	while(Q--) {
		ll Lx, Rx, Ly, Ry, Lz, Rz; cin >> Lx >> Rx >> Ly >> Ry >> Lz >> Rz;
		Lx--; Ly--;Lz--;
		out(
			S[Rx][Ry][Rz] + 
			- ( S[Lx][Ry][Rz] + S[Rx][Ly][Rz] + S[Rx][Ry][Lz] )
			+ ( S[Lx][Ly][Rz] + S[Lx][Ry][Lz] + S[Rx][Ly][Lz] )
			- S[Lx][Ly][Lz]
		);
	}

	
	




	return 0;
}