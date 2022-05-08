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
  ll Q, q, x, k;
  cin >> Q;

  vector<ll> A;

  rep(_,Q) { 
    cin >> q;
    if(q == 1) {
      cin >> x;
      auto it = lower_bound(A.begin(),A.end(),x);
      A.insert(it, x);
    }
    else if(q == 2) {
      cin >> x >> k;
      auto it = upper_bound(A.begin(),A.end(),x);
      int K = distance(A.begin(),it);
      if(K == 0 || K-k < 0) {
        cout << -1 << endl;
      } else {
        cout << A[K-k] << endl;
      }

    } else if(q == 3) {
      cin >> x >> k;
      auto it = lower_bound(A.begin(),A.end(),x);
      int K = distance(A.begin(),it);
      if(K == A.size() || K+(k-1) >= A.size()) {
        cout << -1 << endl;
      } else {
        cout << A[K+(k-1)] << endl;
      }
    } 

  }

  return;
}

int main(){
    solve();
    return 0;
}
