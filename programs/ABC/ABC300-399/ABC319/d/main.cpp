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


int main()
{
	ll N, M; cin >> N >> M;
	vector<ll> L(N); rep(i,N) cin >> L[i];
	vector<ll> S(N+1); S[0] = 0;
	reps(i,1,N+1) S[i] = S[i-1] + L[i-1];


	ll lb = 0, ub = INF_LL;
	while(ub - lb > 1) {
		ll W = (ub + lb)/2;
		if(W == 26) {
			ll a = 0;
		}

		ll lb2 = 0;
		ll ub2 = N+1;
		ll cnt = 0;
		while(lb2 < N) {
			ll nxt = lb2;
			ub2 = N+1;
			while(ub2 - lb2 > 1) {
				ll idx = (ub2 + lb2)/2;

				if(S[idx] + (idx - nxt - 1) - S[nxt] <= W) {
					lb2 = idx;
				} else {
					ub2 = idx;
				}
			}
			cnt++;
			if(cnt > M) break;
		}

		if(cnt <= M) {
			ub = W;
		} else {
			lb = W;
		}
	}

	out(ub)

	return 0;
}