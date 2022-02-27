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

void OK() {
  cout << "Yes" << endl;
  exit(0);
}

void solve(){
  ll N, K;
  cin >> N >> K;

  vector<ll>A(N);
  rep(i,N) cin >> A[i];

  ll X = 0;
  ll cnt = 0;
  unordered_map<ll,int> s;
  rep(i,N) {
    if(s.count(X%N)>0) {
      s.insert(X%N);
    }
    else {
      s[X%N] = i;
    }
    cout << "X%N: " << X%N << endl;
    X += A[X%N];
    if(X%N == 0) {
      cnt = i+1;
    }
  }

  X = 0;
  if(K <= cnt) {
    rep(i,K) X += A[i];
  } else {
    ll X0 =0;
    rep(i,cnt) X0 += A[i];

    X = (K / cnt) * X0;
    ll K0 = K % cnt;
    rep(i,K0) X += A[X % N];
  }
    cout << X << endl;



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

