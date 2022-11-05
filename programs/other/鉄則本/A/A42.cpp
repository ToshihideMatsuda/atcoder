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

#define MAX_N 300000 + 5



void solve() {
  ll N, K; cin >> N >> K;
  vector<pair<ll,ll>> AB(N);
  rep(i,N) {
    ll a,b;
    cin >> a >> b;
    AB[i] = {a,b};
  }
  sort(AB.begin(),AB.end());
  
  ll ans = 1;
  rep(i,N-1) {

    ll B[101];
    rep(i,101) B[i] = 0;
    reps(j,i,N) {
      if(abs(AB[i].first - AB[j].first) <= K) B[AB[j].second]++;
    }

    ll start = MAX(1, AB[i].second - K);
    ll end   = MIN(100, AB[i].second + K);

    ll tmp =0;
    reps(i, start, start + K + 1) tmp += B[i];
    ans = MAX(ans,tmp);

    reps(i, start+K+1, end + 1){
      tmp += B[i] - B[i-K-1]; 
      ans = MAX(ans,tmp);
    }

  }

  cout << ans << endl;



}


int main()
{
  solve();
	return 0;
}