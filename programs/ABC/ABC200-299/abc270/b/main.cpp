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
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N 2*100000+5
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

ll d[2005];
void solve() {
  rep(i,2005) d[i] = INF;
  ll X, Y, Z; cin >> X >> Y >> Z;
  X += 1000;
  Y += 1000;
  Z += 1000;
  queue<tuple<ll,ll, bool>> Q;
  Q.push({1000, 1, false});
  Q.push({1000,-1, false});
  d[1000] = 0;
  while(Q.size() > 0) {
    auto q = Q.front();Q.pop();
    ll nx = get<0>(q) + get<1>(q);
    if(0<= nx && nx <=2001) {
      ll ok = get<2>(q) || nx != Y;

      if(ok) {
        d[nx] = d[get<0>(q)] + 1;
        if(nx == X) {
          cout << d[X] << endl;
          return;
        }
          if(Z == nx) {
              Q.push({nx,-1, true});
              Q.push({nx, 1, true});
          } else {
              Q.push({nx, get<1>(q), get<2>(q)});
          }
        
      }
    }
  }
  
  cout << -1 << endl;


}


int main()
{
  solve();
	return 0;
}