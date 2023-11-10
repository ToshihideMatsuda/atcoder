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

#define MAX_N (2*1000+5)

vector<pair<ll,ll> > G [MAX_N];
ll cost[MAX_N];

void dijkstra(ll start){
  
  priority_queue<pair<ll,ll>, vector<pair<ll, ll> >, greater<pair<ll,ll> > > Q;

  Q.push(make_pair(0,start));

  rep(i, MAX_N) cost[i] = INF_LL;
  cost[start] = 0;

  while(Q.size() > 0) {
      auto from = Q.top();Q.pop();
      ll p = from.second;
      ll fromC = from.first;

      if(fromC != cost[p]) continue;
      
      for(auto to : G[p]) {
          ll q = to.second, toC = to.first;

          
          if(fromC + toC < cost[q]) {
              cost[q] = fromC + toC;
              Q.push(make_pair(cost[q] ,q));
          }
      }
  }

}



int main()
{
	ll n, a, b, c; cin >> n >> a >> b >> c;

	ll d[n][n];
	rep(i,n)rep(j,n) cin >> d[i][j];

	rep(i,n) {
		G[i].push_back({0, i + n});
		rep(j,n) if(i != j) {
			G[i].push_back({d[i][j] * a, j});
			G[i+n].push_back({d[i][j] * b + c, j + n});
		}
	}

	dijkstra(0);
	

	out(MIN(cost[n-1], cost[n-1 + n]));

	
	return 0;
}