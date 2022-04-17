
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
  ll N, Q;
  cin >> N;
  vector<ll> mp[N + 5];


  rep(i,N) {
    ll A;
    cin >> A;
    mp[A].push_back(i+1);
  }

  cin >> Q;

  rep(_,Q) {
    ll L,R,X;
    cin >> L >> R >> X;

    auto itL = lower_bound(mp[X].begin(), mp[X].end(), L) ;
    auto itR = lower_bound(mp[X].begin(), mp[X].end(), R+1) ;

    cout << itR - itL << endl;
    
  }
}



int main(){
    solve();
    return 0;
}
