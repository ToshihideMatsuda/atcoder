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



ll hour[25];

void solve() {
  ll D, N; cin >> D >> N;
  ll Day[365+5];
  reps(i, 1, 365+1) Day[i] = 24;
  rep(i,N) {
    ll L, R, H;
    cin >> L >> R >> H;
    reps(i,L,R+1){
      Day[i] = MIN(Day[i], H);
    }
  }

  
  ll ans = 0;
  reps(i,1,D+1) ans += Day[i];

  cout << ans << endl;
  




}


int main()
{
  solve();
	return 0;
}