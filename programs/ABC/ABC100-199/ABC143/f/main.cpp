#include <bits/stdc++.h> 
#include <atcoder/all>

using namespace atcoder;
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

#define MAX_N 300 + 5


ll N, M, L;
ll d[MAX_N][MAX_N];


void warshall_floyd() {
  reps(k,1,N+1) {           // 経由する頂点
      reps(i,1,N+1) {       // 始点
          reps (j,1,N+1) {  // 終点
		  	if(i == 1 && j == 3 && k == 2) {
				ll p =0;
			}
              d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
          }
      }
    }
}


int main()
{
	 cin >> N >> M >> L;
	reps(i,1,N+1) reps(j,1,N+1) d[i][j] = (i == j ? 0 : INF);
	rep(i,M){
	  	ll a, b, c;
	  	cin >> a >> b >> c;
	  	d[a][b] = c;
	  	d[b][a] = c;
	}

	warshall_floyd();

	vector<pair<ll,ll>> G;
	reps(i,1,N+1) reps(j,i+1,N+1) if(i!=j && d[i][j] <= L){
		G.push_back({i,j});
	}

	reps(i,1,N+1) reps(j,1,N+1) d[i][j] = (i == j ? 0 : INF);
	for(auto [i,j]:G) {
		d[i][j] = 1;
		d[j][i] = 1;
	}
	warshall_floyd();

	vector<ll> ans;
	ll Q; cin >> Q;
	while(Q--) {
		ll s, t; cin >> s >> t;
		if(d[s][t] == INF) ans.push_back(-1);
		else ans.push_back(d[s][t]-1);
	}

	OUT(ans,endl)



	return 0;
}