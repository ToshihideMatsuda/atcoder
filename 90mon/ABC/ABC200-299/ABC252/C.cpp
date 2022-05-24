#include <bits/stdc++.h> 
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

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}

void solve(){
  ll N;
  cin >> N;
  vector<string> S(N);
  rep(i,N) cin >> S[i];

  ll ans = INF_LL;
  rep(i,10) {
    int cnt[10];
    rep(k,10) cnt[k] = 0;
    rep(j,N) rep(k,10) if(S[j][k] - '0' == i) {
      cnt[k] ++;
    }
    ll m = 0,indx = -1;
    rep(k,10){
      if(cnt[k] >= m) {
        m = cnt[k];
        indx = k;
      }
    }

    if(indx < 0)
      continue;

    ll tmp = (m - 1) * 10 + indx % 10;

    ans = min (ans, tmp);

  }

  cout << ans << endl;


}


int main()
{
  solve();
	return 0;
}