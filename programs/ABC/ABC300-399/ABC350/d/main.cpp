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
#define MINF_LL (-9223372036854775808LL)
#define MOD 998244353

#define MAX_N (2*100000+5)
set<ll> G[MAX_N];

int main()
{
	ll N, M; cin >> N >> M;
	rep(i,M) {
		ll a, b; cin >> a >> b;
		G[a].insert(b);
		G[b].insert(a);
	}

	ll ans = 0;
	vector<bool> ck (N+1, false);
	reps(x,1,N+1) if(ck[x] == false){
		queue<ll> Q; Q.push(x);
		ck[x] = true;

		vector<ll> P;
		P.push_back(x);

		set<pair<ll,ll>> S;

		while(Q.size() > 0) {
			auto q = Q.front(); Q.pop();
			for(auto g : G[q]) {
				if(q < g) {
					S.insert( {q,g});
				} else {
					S.insert( {g,q});
				}

				if(ck[g] == false){
					ck[g] = true;
					Q.push(g);
					P.push_back(g);
				}
			}
		}

		ll all = (P.size() * (P.size() -1)) / 2;
		ans += all - S.size();

	}

	out(ans)
	return 0;
}