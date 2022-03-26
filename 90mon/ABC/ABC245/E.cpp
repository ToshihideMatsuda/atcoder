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
  vector<ll> A(N),B(N),C(M),D(M);
  multiset<ll> ms;
  rep(i,N) cin >> A[i];
  rep(i,N) cin >> B[i];
  rep(i,M) cin >> C[i];
  rep(i,M) cin >> D[i];

  vector<tuple<ll, ll, ll>> ABCD;
  rep(i,N) ABCD.push_back({A[i], B[i], 0}); //ch
  rep(i,M) ABCD.push_back({C[i], D[i], 1}); //box

  sort(ABCD.begin(), ABCD.end(), greater<tuple<ll, ll, ll>>());

  ll a, b, t;
  rep(i, ABCD.size()) {
    tie(a, b, t) = ABCD[i];
    if (t == 0) { //ch
      auto e = ms.lower_bound(b);
      if(e == ms.end() || ms.empty())  
        NO();
      
      ms.erase(e);
    } else {  //box
      ms.insert(b);
    }
  }
  YES();

}



int main(){
    solve();
    return 0;
}

