#include <bits/stdc++.h> 

using namespace std;

#define debug false

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)


#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 1000000000+7

#if debug == true
    #define MAX_N 100 + 5
#else
    #define MAX_N 100000+5
#endif

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}
void UNSOLVABLE() {
  cout << "UNSOLVABLE" << endl;
}

vector<ll> G[MAX_N];
ll OE[MAX_N];

void solve(){
  ll N, Q;
  cin >> N >> Q;
  

  rep(i,N-1) {
    ll a, b;
    cin >> a >> b;
    G[b].push_back(a);
    G[a].push_back(b);
  }

  queue<pair<ll,ll>> Qu;
  Qu.push({1,1});
  OE[1] = 1;

  while(Qu.size() > 0) {
    ll v, f;
    tie(v,f) = Qu.front(); Qu.pop();
    
    ll nf = -1 * f;
    for(ll u : G[v]) {
        if(OE[u] == 0) {
            Qu.push({u,nf});
            OE[u] = nf;
        }
    }
  }

  rep(_, Q) {
      ll c, d;
      cin >> c >> d;
      if(OE[c] == OE[d]) cout << "Town" << endl;
      else cout << "Road" << endl;
  }

}



int main(){
    solve();
    return 0;
}
