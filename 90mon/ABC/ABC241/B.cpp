#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <numeric>

using namespace std;

#define debug false

#define rep(i,n)     for(int i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(int i = m; i < n; i++ ) 


typedef long long ll;

#define INF 1 << 28
#define MINF -1*(1 << 28)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#if debug == true
    #define MAX_N 100 + 5
#else
    #define MAX_N 2*100000 + 5
#endif


void solve(){
  int M,N;
  vector <int>A,B;
  cin >> N >> M;
  A.resize(N);B.resize(M);
  rep(i,N) cin >> A[i];
  rep(i,M) cin >> B[i];

  for(int b :B) {
    bool ok = false;
    rep(i,A.size()) {
      if(A[i] == b) {
        A.erase(A.begin() + i);
        ok = true;
        break;
      }
    }

    if(ok == false) {
      cout << "No" << endl;
      return;
    }

  }

  cout << "Yes" << endl;
  return;
}


int main(){

#if debug == true
    while(true){
        cout << "---debugMode---" << endl;
#endif
        solve();
        cout << endl;
#if debug == true
    }
#endif

    return 0;
}
