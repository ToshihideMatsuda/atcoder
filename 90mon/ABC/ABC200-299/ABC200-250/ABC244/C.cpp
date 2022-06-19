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
  int N;
  cin >> N;

  bool V[2*N+2];
  rep(i,2*N+2) V[i] = false;

  cout << 1 << endl;
  V[1] = true;

  rep(i,N) {
      int a;
      cin >> a;
      V[a] = true;
      reps(i,2,2*N+2) {
          if(V[i] == false) {
                cout << i << endl;
                V[i] = true;
                break;
          }
      }
  }
}



int main(){
    solve();
    return 0;
}

