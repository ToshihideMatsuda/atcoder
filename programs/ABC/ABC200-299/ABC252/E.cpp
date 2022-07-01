#include <bits/stdc++.h> 
#include <unordered_map> 
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define max(a,b)   (a>b?a:b)
#define max3(a,b,c) max(a,max(b,c))
#define min(a,b)   (a<b?a:b)
#define min3(a,b,c) min(a,min(b,c))


#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}

vector<pair<ll,ll> > G [MAX_N];
ll cost[MAX_N];

unordered_map<ll,ll> road;
ll ans[MAX_N];

void solve(){
  ll N, M;
  cin >> N >> M;
  rep(i,M) {
      ll a, b, c;
      cin >> a >> b >> c;
      G[b].push_back(make_pair(c,a));
      G[a].push_back(make_pair(c,b));
      road[min(a,b) + 2*1000000 * max(a,b)] = i +1;
  }
  
  priority_queue<pair<ll,ll>, 
                vector<pair<ll, ll> >, greater<pair<ll,ll> > > Q;

  Q.push(make_pair(0,1));

  rep(i, MAX_N) cost[i] = INF_LL;
  cost[1] = 0;

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
              ans[q] = road[min(p,q) + 2*1000000 * max(p,q)];
          }
      }
  }

  reps(i,2, N+1) {
      cout << ans[i] << " ";
  }
  cout << endl;



}


int main()
{
  solve();
	return 0;
}