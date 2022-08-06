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


vector<vector<ll>> ans;

void solve() {
   ll N, M; cin >> N >> M;  

   queue<vector<ll>> Q;
   reps(i,1,M+1) {
    vector<ll> tmp;
    tmp.push_back(i);
    Q.push(tmp);
   }
   while(Q.size() > 0) {
    vector<ll> v = Q.front(); Q.pop();
    if(v.size() == N) {
      ans.push_back(v);
      continue;
    }
    
    ll r = M - v.back();
    if(v.size() + r < N) {
      //届かない
      continue;
    }

    reps(i,v.back()+1, M + 1 )  {

      if(M - i + 1 < N-v.size()) {
        continue;
      }

      vector<ll> tmp = v;

      tmp.push_back(i);
      Q.push(tmp);
    }
   }

   sort(ans.begin(), ans.end());
   rep(i,ans.size()) {
    rep(j,N) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
   }


}


int main()
{
  solve();
	return 0;
}