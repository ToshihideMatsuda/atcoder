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
  ll H, W; cin >> H >> W;
  ll r,c; cin >> r >> c;
  ll N; cin >> N;
  map<ll,vector<ll>> wallR, wallC;
  rep(i,N) {
    ll r, c; cin >> r >> c;
    wallR[r].push_back(c);
    wallC[c].push_back(r);
  }


  for(auto idx = wallR.begin();idx != wallR.end(); ++ idx) {
    (*idx).second.push_back(MINF_LL);
    (*idx).second.push_back(INF_LL);
    sort((*idx).second.begin(),(*idx).second.end());
  }

  for(auto idx = wallC.begin();idx != wallC.end(); ++ idx) {
    (*idx).second.push_back(MINF_LL);
    (*idx).second.push_back(INF_LL);
    sort((*idx).second.begin(),(*idx).second.end());
  }

  ll Q; cin >> Q;
  rep(_,Q) {
    char d; ll l; cin >> d >> l;

    if(d == 'D') {
      ll tmpR = MIN(r + l,H);
      if(wallC[c].size() == 0) {
        r = tmpR;
      } else {
        auto idx = lower_bound(wallC[c].begin(),wallC[c].end(),r);
        r = MIN( (*idx) - 1, tmpR);
      }
    } else if(d == 'U') {
      ll tmpR = MAX(r - l,1);
      if(wallC[c].size() == 0) {
        r = tmpR;
      } else {
        auto idx = lower_bound(wallC[c].begin(),wallC[c].end(),r);
        idx--;
        r = MAX( (*idx)+1, tmpR);
      }
    } else if(d == 'R') {
      ll tmpC = MIN(c + l,W);
      if(wallR[r].size() == 0) {
        c = tmpC;
      } else {
        auto idx = lower_bound(wallR[r].begin(),wallR[r].end(),c);
        c = MIN( (*idx) - 1, tmpC);
      }
    } else if(d == 'L') {
      ll tmpC = MAX(c - l,1);
      if(wallR[r].size() == 0) {
        c = tmpC;
      } else {
        auto idx = lower_bound(wallR[r].begin(),wallR[r].end(),c);
        idx--;
        c = MAX( (*idx)+1, tmpC);
      }
    }
    cout << r << " " << c << endl; 
  }




}


int main()
{
  solve();
	return 0;
}