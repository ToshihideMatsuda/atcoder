#include <bits/stdc++.h> 
#include <unordered_map>
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
#define out2(s) cout << s;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
vector<ll> deg;
bool ck[MAX_N]; 
ll order[MAX_N];

void clear() { rep(i,MAX_N) ck[i] = false; }


void solve() {
  ll N, M; cin >> N >> M;

  deg.resize(N+5);

  set<pair<ll,ll>> s;

  rep(i,M) { 
    ll a, b; cin >> a >> b; 
    s.insert({a,b});
  }

  for(auto c : s) {
    ll a, b; tie(a,b) = c;
    G[b].push_back(a);
    deg[a]++;
  } 


  ll r = 0;
  reps(i,1,N+1) {
    if(deg[i] == 0) {
      if( r != 0) {
        out("No");
        return;
      }
      r = i;
    }
  }
  
  order[r] = N;

  ll c = 1;
  while(order[r] > 1) {
    ll nx = 0;

    for(auto g :G[r]) {
      deg[g] --;
      if(deg[g] == 0) {
        
        if( nx != 0) {
          out("No");
          return;
        }
        nx = g;
      }
    }

    order[nx] = order[r] -1;
    r = nx;
  }

  out("Yes")
  reps(i,1,N+1) {
    out2(order[i])
    out2(" ")
  }

}




int main()
{
  solve();
	return 0;
}