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


#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

ll N, Q; 
vector<vector<ll>> S;

ll g(ll a, ll b) {
	ll n = (a/N);
	ll m = (b/N);
	return 	n * m * S[N][N] +
			n * S[N][b%N] + 
			m * S[a%N][N] + 
			S[a%N][b%N]; 
}
ll f( ll a, ll b, ll c , ll d) {
	return g(c,d) - g(c,b) - g(a,d) + g(a,b);
}

int main()
{
	cin >> N >> Q;
	vector<string> P(N);
	rep(i,N) {
		cin >> P[i];
	}

	S = vector(N+1,vector<ll>(N+1,0));	
	rep(i,N)rep(j,N) {
		S[i+1][j+1] =  S[i][j+1] + S[i+1][j] - S[i][j] + (P[i][j] == 'B' ? 1 : 0);
	}

	while(Q--) {
		ll a, b, c, d; cin >> a >> b >> c >> d;

		ll ans = f(a, b, c+1, d+1);
		out(ans)
	}


}