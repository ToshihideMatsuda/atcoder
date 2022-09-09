#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <unordered_map>
#include <unordered_map>
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) max(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) min(a,MIN(b,c))

#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5


void solve() {
	ll N,M; cin >> N >> M;
	vector<ll>A(N+1);rep(i,N)cin >> A[i+1];
	vector<ll>G[N+1];
	vector<ll>C(N+1);
	rep(i,N+1)C[i] = 0;
	rep(i,M){
		ll u,v;cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
		C[u] += A[v];
		C[v] += A[u];
	}

  ll lb = 0, ub = 0;
  rep(i,N+1) ub = max(ub,C[i]);

  while(lb + 1 < ub) {
  	ll mid = (lb + ub) / 2;

    vector<ll> cost(C);
  
    queue<ll> Q;
    bool ck [N+1];
  	ck[0]=false;
    reps(i,1,N+1) if(cost[i] <= mid ) {
      Q.push(i);
      ck[i]=true;
    } else {
      ck[i]=false;
    }

    while(Q.size() > 0) {
      auto q = Q.front(); Q.pop();
      
      for(auto g : G[q]) if(!ck[g]){
        cost[g] -= A[q];
        if(cost[g] <= mid ) {
          Q.push(g);
          ck[g]=true;
        }
      }
    }
    
    ll cnt=0;
    rep(i,N+1)if(ck[i])cnt++;

    if(cnt == N) { // midはOK
      ub = mid;
    } else {
      lb = mid;
    }
  }

  cout << ub << endl;

}


int main()
{
  solve();
	return 0;
}
