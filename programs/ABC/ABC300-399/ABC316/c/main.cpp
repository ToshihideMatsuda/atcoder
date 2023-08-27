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

#define MAX_N (10+1)
ll G[MAX_N][MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }


int main()
{
	ll N, M; cin >> N >> M;
	rep(i,M) { 
		ll a, b, c; cin >> a >> b >> c; 
		G[a][b] = c;
		G[b][a] = c;
	}

	ll ans = 0;
	for(int i = 1; i < (1 << N); i++ ){
		vector<ll> seed;

		
		rep(j,N) if( (i & (1 << j)) > 0 ) {
			seed.push_back(j+1);
		}
		if(seed.size() < 2) continue;
		do {
			ll tmp = 0;
			rep(i,seed.size()-1) {
				ll from = seed[i];
				ll to = seed[i+1];
				if(G[from][to] == 0) {
					goto next;
				}
				tmp += G[from][to] ;
			}
			ans = MAX(ans,tmp);

			next: 
				continue;
		} while(next_permutation(seed.begin(),seed.end()));

	}
	out(ans)
	
	return 0;
}