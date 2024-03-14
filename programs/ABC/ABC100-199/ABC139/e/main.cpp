#include "bits/stdc++.h"
using namespace std;

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

ll N; 
vector< pair<ll,ll> > G[1000+5][1000+5];
ll H[1000+5][1000+5];
bool visited[1000+5][1000+5];
		
void dfs (pair<ll,ll> p, vector<vector<bool>>& s) {
	auto [i,j] = p;
	visited[i][j] = true;
	s[i][j] = true;

	for(auto g: G[i][j]) {
		auto [g1,g2] = g;
		if(s[g1][g2]) {
			out(-1)
			exit(0);
		}
		if(visited[g1][g2]) continue;

		dfs(g,s);
	}
	s[i][j] = false;
};

int main()
{
	cin >> N;

	
	reps(i,1,N+1) {
		pair<ll,ll> prev = {-1,-1}; 
		rep(j,N-1) {
			ll a; cin >> a;

			ll s = MIN(a,i);
			ll l = MAX(a,i);
			if(prev.first != -1) {
				G[prev.first][prev.second].push_back({s,l});
				H[s][l]++;
			}
			prev = {s,l};
		}
	}

	reps(i,1,N+1) reps(j,i+1,N+1)  if(visited[i][j] == false) {
		vector s = vector(N+1,vector(N+1,false));
		dfs({i,j},s);
	}
	
	ll cnt = 0;
	vector<pair<ll,ll>>T;
	reps(i,1,N+1) reps(j,i+1,N+1)  if(H[i][j] == 0) {
		T.push_back({i,j});
	}
	ll ans=0;
	while(cnt < N*(N-1)/2){
		ans++;
		vector<pair<ll,ll>> U;
		for(auto [i,j]:T){
			cnt ++ ;
			for(auto [p,q]:G[i][j]){
				H[p][q]--;
				if(H[p][q] == 0) {
					U.push_back({p,q});
				}
			}
		
		}

		T = move(U);
	}

	
	out(ans)


	return 0;
}

