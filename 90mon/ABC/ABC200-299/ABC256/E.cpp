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


void solve() {
  ll N; cin >> N;
  vector<ll> X(N); rep(i,N) { cin >> X[i]; X[i]--;} 
  vector<ll> C(N); rep(i,N) cin >> C[i];
  bool visit[N]; rep(i,N) visit[i] = false;

  ll ans = 0;
  rep(i,N) {
    if(visit[i]) continue; //visited
    set<ll> S;
    ll nx = i;
    while(true) {
      if(S.count(nx)) {
        // nx からの閉路あり。最小コストをプラス
        ll tmp = INF_LL;
        ll end = nx;
        do{
          tmp = min(C[nx],tmp);
          nx = X[nx];
        }while( nx != end);
        ans += tmp;
        break;
      } 
      if(visit[nx]) break;

      visit[nx] = true;
      S.insert(nx);
      nx = X[nx];
    }
  }
  
  cout << ans << endl;
}


int main()
{
  solve();
	return 0;
}