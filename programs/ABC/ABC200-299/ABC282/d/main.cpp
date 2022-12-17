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

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

ll color[MAX_N];
unordered_map<ll,ll> color2cnt[2];

void solve() {
  ll N, M; cin >> N >> M;
  readG(M);

  reps(i,1,N+1) {
    if(color[i] == 0) {
      queue<pair<ll,ll>> Q;
      Q.push({i,-1});
      color[i] = i;
      color2cnt[0][i]++;
      while(Q.size() > 0) {
        ll q, pre;
        tie(q, pre) = Q.front(); Q.pop();
        for(auto g : G[q]) if(g != pre){
          if(color[g] != 0) {
            if(color[g] !=  -1* color[q]) {
              //not color
              cout << 0 << endl;
              return;
            } else {
              continue;
            }
          }
          color[g] = -1* color[q];
          if(color[g] > 0) {
            color2cnt[0][color[g]]++;
          } else {
            color2cnt[1][- color[g]]++;
          }
          Q.push({g,q});
        }
      }
    }
  }


  ll ans = 0;

  vector<ll> cnt;


  for(auto idx = color2cnt[0].begin(); idx != color2cnt[0].end(); ++idx) {
    ll k, v; tie(k, v) = (*idx);
    cnt.push_back(color2cnt[0][k] +  color2cnt[1][k]);
  }

  ll sum = 0;
  rep(i, cnt.size()) sum += cnt[i];
  rep(i,cnt.size()-1) {
    sum -= cnt[i];
    ans += cnt[i] * sum;
  }

  reps(i,1,N+1) {
    if(color[i] > 0) {
      ll b = color2cnt[1][color[i]];
      ans += b - G[i].size();
    }
  }
  cout << ans << endl;

}


int main()
{
  solve();
	return 0;
}