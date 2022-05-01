#include <bits/stdc++.h> 

using namespace std;

#define debug false

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)


#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 1000000000+7

#if debug == true
    #define MAX_N 100 + 5
#else
    #define MAX_N 3000+5
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
  ll N;
  cin >> N;
  vector<ll> C(N);
  rep(i,N) cin >> C[i];

  sort(C.begin(),C.end());

  ll dp = 1;
  rep(i,N){
    dp *=(C[i]-i);
    dp %= MOD;
  }
  cout << dp << endl;


}



int main(){
    solve();
    return 0;
}
