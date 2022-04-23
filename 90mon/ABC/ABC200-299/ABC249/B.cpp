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

  bool b[2];
  bool a[100];

void solve(){
  string S;
  cin >> S;
  bool b[2];
  bool a[100];

  rep(i,2) b[i] = false;
  rep(i,100) a[i] = false;

  rep(i,S.size()) {
    if('a' <= S[i] && S[i] <= 'z') {
      b[0] = true;
    } else if('A' <= S[i] && S[i] <= 'Z') {
      b[1] = true;
    }

    if(a[S[i] - 'A']) {
      cout << "No" << endl;
      return;
    }
    a[S[i] - 'A'] = true;
  }
  
  if(b[1] && b[0]) {
    cout << "Yes" << endl;
    return;
  }
  cout << "No" << endl;

}



int main(){
    solve();
    return 0;
}
