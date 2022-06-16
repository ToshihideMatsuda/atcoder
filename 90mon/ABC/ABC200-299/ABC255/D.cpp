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
  ll N, Q; cin >> N >> Q;
  vector<ll> A(N);
  rep(i,N) cin >> A[i];

  sort(A.begin(), A.end());
  vector<ll> R(N);
  R[0] = A[0];
  reps(i,1,N) R[i] = R[i-1] + A[i];

  rep(_,Q) {
    ll X; cin >> X;

    auto idx = lower_bound(A.begin(), A.end(), X);
    ll i = idx - A.begin();
    ll ans =  0;
    if(i == 0) {
      ans = (R[N-1] - X*N );
    } else if(i < N ) {
      ans =  abs(X*i - R[i-1]) + abs( (R[N-1] - R[i-1]) - X*(N-i) );
    } else {
      ans = abs(X*N - R[N-1]);
    }
    cout << ans << endl;


  }


}


int main()
{
  solve();
	return 0;
}