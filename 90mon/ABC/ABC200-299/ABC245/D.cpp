#include <bits/stdc++.h> 

using namespace std;

#define debug false

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 



#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#if debug == true
    #define MAX_N 100 + 5
#else
    #define MAX_N 10000 + 5
#endif

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}
void UNSOLVABLE() {
  cout << "UNSOLVABLE" << endl;
}



void solve(){
  ll N, M;
  cin >> N >> M;

  vector<ll> A(N+1),C(N+M+1), B(M+1);
  rep(i, N+1) cin >> A[i];
  rep(i, N+M+1) cin >> C[i];


  reverse(A.begin(), A.end());
  reverse(C.begin(), C.end());

  rep(i, M +1) {
     B[i]= C[i] / A[0];

    rep(j,N+1) {
      C[i+j] -= B[i] * A[j];
    }
  }

  reverse(B.begin(), B.end());

  rep(i, M +1) {
    cout << B[i] << " ";
  }
  cout << endl;

}



int main(){
    solve();
    return 0;
}

