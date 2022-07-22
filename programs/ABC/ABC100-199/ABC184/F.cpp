#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define max(a,b)   (a>b?a:b)
#define max3(a,b,c) max(a,max(b,c))
#define min(a,b)   (a<b?a:b)
#define min3(a,b,c) min(a,min(b,c))

#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5


void solve() {
  ll N, T; cin >> N >> T;
  ll NN[2] = {N/2, N - N/2};
  vector<ll> A[2];
  rep(i,2){
    A[i].resize(NN[i]);
    rep(j,NN[i]) cin >> A[i][j];
  }

  vector<ll> S[2];
  S[1].push_back(MINF_LL);
  S[1].push_back(INF_LL);
  rep(a,2) {
    for(int i = 0; i < 1 << NN[a]; i ++) {
      ll sum = 0;
      ll ii = i;
      ll j = 0;
      while(ii > 0) {
        if((ii & 1) == 1) {
          sum += A[a][j];
        }
        j ++;
        ii = ii >> 1;
      }
      S[a].push_back(sum);
    }
  }

  rep(a,2) sort(S[a].begin(),S[a].end());

  ll ans = 0;
  for(auto s0 : S[0]) {
    if(T < s0) continue;
    else if(T == s0) ans = T;
    else {
      auto idx = lower_bound(S[1].begin(),S[1].end(),(T - s0));

      if(*idx == T-s0) ans = T;
      else {
        idx--;

        if(*idx == MINF_LL) {
          continue;
        } else {
          ans = max(ans, s0 + *idx);
        }
      }


    }

  }

  cout << ans << endl;




}


int main()
{
  solve();
	return 0;
}