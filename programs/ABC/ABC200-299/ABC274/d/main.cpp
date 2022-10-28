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
  ll N, x, y; cin >> N >> x >> y;
  vector<ll> A(N+1);rep(i,N) cin >> A[i+1];
  set<pair<ll,ll>> s0, sl;

  s0.insert({A[1],0});
  sl.insert({x,y});

  revs(i, N, N/2+1) {
    bool ydic = (i%2==0);
    set<pair<ll,ll>> tmp;
    
    for(auto s : sl) {
      if(ydic) {
        tmp.insert({s.first, s.second + A[i]});
        tmp.insert({s.first, s.second - A[i]});
      } else {
        tmp.insert({s.first + A[i], s.second});
        tmp.insert({s.first - A[i], s.second});
      }
    }
    
    sl = move(tmp);
  } 

  
  reps(i, 2, N/2+1) {
    bool ydic = (i%2==0);

    set<pair<ll,ll>> tmp;

    for(auto s : s0) {
      if(ydic) {
        tmp.insert({s.first, s.second + A[i]});
        tmp.insert({s.first, s.second - A[i]});
      } else {
        tmp.insert({s.first + A[i], s.second});
        tmp.insert({s.first - A[i], s.second});
      }
    }

    s0 = move(tmp);
  }

  bool ok = false;
  for(auto s : s0) if(sl.count(s)) ok = true;

  if(ok) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }


}


int main()
{
  solve();
	return 0;
}