#include <bits/stdc++.h> 
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

#define MAX_N 100000+5

ll N;
vector<ll> G[MAX_N];
ll d[MAX_N];


void calcD(ll from) {
  rep(i,MAX_N) d[i] = -1;
  queue<ll> Q;
  Q.push(from);
  d[from] = 0;

  while(Q.size() > 0) {
    auto q = Q.front(); Q.pop();
    for(auto g : G[q]) {
      if(d[g] == -1) {
        d[g] = d[q] + 1;
        Q.push(g);
      }
    }
  }

}

void solve() {
  cin >> N;
  rep(i,N-1) {
    ll A,B;
    cin >>  A >> B;
    G[A].push_back(B);
    G[B].push_back(A);
  }

  calcD(1);
  ll e = 0;
  ll mx = 0;
  reps(i,1,N+1) {
    if(mx < d[i]){
      mx = d[i];
      e = i;
    }
  }

  calcD(e);
  mx = 0;
  reps(i,1,N+1) mx = MAX(mx,d[i]);

  cout << mx + 1 << endl;

}


int main()
{
  solve();
	return 0;
}