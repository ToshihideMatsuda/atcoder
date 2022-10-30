#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) max(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) min(a,MIN(b,c))

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N 2*100000+5
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

void solve() {
  vector<string> S(9); 
  rep(i,9) cin >> S[i];

  set<pair<ll,ll>> s;

  rep(r,9)rep(c,9) if(S[r][c] == '#') s.insert({r,c});


  set<set<pair<ll,ll>>> ans;
  for(auto p1:s) {
    for(auto p2:s) if(p1 != p2){
      ll dx0 = p2.first - p1.first;
      ll dy0 = p2.second - p1.second;

      ll dx1 = p1.first  - p2.first;
      ll dy1 = p1.second - p2.second;

      pair<ll,ll> new0 = {p2.first + dy0, p2.second - dx0 };
      pair<ll,ll> new1 = {p1.first - dy1, p1.second + dx1 };

      if(s.count(new0) && s.count(new1)) {
        ans.insert({p1,p2,new0,new1});
      }


    }
  }

  cout << ans.size()<< endl;


}


int main()
{
  solve();
	return 0;
}