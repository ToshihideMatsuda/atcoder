#include "bits/stdc++.h"
#include <iostream>
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
#define out(s) cout << s << endl;
#define out0(s) cout << s;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N (2*100000+5)

// G[from]= {cost, to}
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
	ll N; cin >> N;
	
	
 	reps(i,1,N) {
      //以下のロジックでグラフGに頂点aから頂点bへのコストcを入れておく
      ll a, b, x;
      cin >> a >> b >> x;
      
      G[i].push_back(make_pair(a,i+1));
      G[i].push_back(make_pair(b,x));
  	}
  	
  	dijkstra(1);
  	
  	out(cost[N]);
	
	
	return 0;
}
