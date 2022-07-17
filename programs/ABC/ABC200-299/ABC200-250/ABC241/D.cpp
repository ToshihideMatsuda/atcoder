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

  multiset<ll> A;


  rep(_,Q) { 
    cin >> q;
    if(q == 1) {
      cin >> x;
      A.insert(x);
    }
    else { 
      if(q == 2) {
        bool check = true;
      cin >> x >> k;
      auto it = A.upper_bound(x);
      rep(_,k) {
        if(it == A.begin()) {
          check = false;
          break;
        }
        it--;
      }
      if(check)cout << *it << "\n";
      else cout << "-1\n";

    } else if(q == 3) {
        bool check = true;
      cin >> x >> k;
      auto it = A.lower_bound(x);

      rep(_,k-1) {
        if(it == A.end()) {
          check = false;
          break;
        }
        it++;
      }

      if(it == A.end()) {
          check = false;
      }
      if(check)cout << *it << "\n";
      else cout << "-1\n";
    } 
    }

    next:
    continue;

  }

  return;
}

int main(){
    solve();
    return 0;
}
