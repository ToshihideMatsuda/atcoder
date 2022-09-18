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

#define MAX_N 2*100000+5

void solve() {
  ll N; cin >> N;

  map<pair<ll,ll>,ll> XY;
  vector<ll> X(N), Y(N);
  rep(i,N) cin >> X[i] >> Y[i];
  rep(i,N) XY[{X[i],Y[i]}] = i;

  ll root[N];
  rep(i,N) root[i] = -1;
/*
(i−1,j−1)
(i−1,j)
(i,j−1)
(i,j+1)
(i+1,j)
(i+1,j+1)
*/
  ll dx[6] = {-1, -1,  0, 0, 1, 1}; 
  ll dy[6] = {-1, 0 , -1, 1, 0, 1};

  rep(i,N) {
    queue<pair<ll,ll>> Q;
    Q.push({i,i});
    while(Q.size() > 0) {
        auto q = Q.front();Q.pop();
        if(root[q.first] != -1) continue;
        root[q.first] = q.second;
        rep(j,6) {
            pair<ll,ll> p =  {X[q.first] + dx[j], Y[q.first] + dy[j]};
            if( XY.count(p) ) {
                Q.push({XY[p],q.second});
            }
        }
    }
  }

  set<ll> cnt;

  rep(i,N) cnt.insert(root[i]);
  cout << cnt.size() <<endl;

}


int main()
{
  solve();
	return 0;
}