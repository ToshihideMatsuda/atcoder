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
    #define MAX_N 200000+9
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


ll c[MAX_N];

void solve(){
  ll N;
  cin >> N;
  rep(i,N) {
    int A;
    cin >> A;
    c[A]++;
  }

  ll ans = 0;

  reps(i, 1, MAX_N) {
    if(c[i] > 0) {
      for(int j = i; j <= MAX_N; j += i) {
        if(c[j] > 0 && c[j/i] > 0) {
          ans += c[i]*c[j]*c[j/i];
        }
      }
    }
  }
  cout << ans << endl;

}



int main(){
    solve();
    return 0;
}
