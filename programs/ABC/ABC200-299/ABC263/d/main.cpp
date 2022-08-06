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
  ll N, L, R ; cin >> N >> L >> R;
  vector<ll> A(N); rep(i,N) cin >> A[i];

  ll dpr[N+5], dpl[N+5];
  reps(i,0,N+5) {
    dpr[i] = 0;
    dpl[i] = 0;
  }

  reps(i,1,N+1) {
    dpl[i]   = min(dpl[i-1] + A[i-1], L*i);
    dpr[i]   = min(dpr[i-1] + A[N-i], R*i);
  } 

  

  ll ans = INF_LL;
  rep(i,N+1) ans = min(ans, dpl[i] + dpr[N-i]);

  cout << ans << endl;

}


int main()
{
  solve();
	return 0;
}