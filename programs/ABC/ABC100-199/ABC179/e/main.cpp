#include <bits/stdc++.h> 
#include <atcoder/all>
using namespace atcoder;
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

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

// Σ A_i [i in 1 ... N] 
// = X+X^2+X^4+X^8+ ... +X^(2^N-1) mod M

int main()
{
	ll N, X, M; cin >> N >> X >> M;

	map<ll,ll> mp;
	ll A = X;
	ll i = 1;
	bool loop = true;
	while(mp.count(A) == false) {
		mp[A] = i;
		A = A*A;
		A %= M;
		i++;
		if(N < i) {
			loop = false;
			break;
		}
	}

	ll s,e;
	if(loop) {
		s = mp[A];
		e = i-1;
	} else {
		s = 1;
		e = N;
	}


	ll loop_len = e-s+1;
	ll loop_cnt = (N+1-s)/loop_len; 
	ll loop_rem = N - ( (s-1) + loop_len * loop_cnt );

	ll ans = 0;

	A = X;
	rep(i,s-1) {
		ans += A;

		A = A*A;
		A %= M;
	}

	ll loopSum = 0;
	reps(i,s,e+1) {
		loopSum += A;

		A = A*A;
		A %= M;
	}
	ans += loopSum * loop_cnt;

	rep(i,loop_rem) {
		ans += A;

		A = A*A;
		A %= M;
	}

	out(ans);


	






	return 0;
}