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
  ll N, L, K; cin >> N >> L >> K;
  vector<ll> A(N+2);
  A[0] = 0; A[N+1] = L;
  rep(i,N) cin >> A[i+1];

  vector<ll> R(N+1);
  rep(i,N+1) R[i] = A[i+1] - A[i];

  ll lb = 0, ub = INF_LL;

  rep(i,N) lb = MIN(lb, A[i]);
  
  while(ub - lb > 1) {
    ll mid  = (ub + lb) / 2;

    ll len = 0;
    ll k = 0;
    ll idx = 0;
    rep(i,N+1) {
      len += R[i];
      if(len >= mid) {
        len = 0;
        k++;
      }
    }

    if(k >= K+1) {
      lb = mid;
    } else {
      ub = mid;
    }
  }

  cout << lb << endl;

}


int main()
{
  solve();
	return 0;
}