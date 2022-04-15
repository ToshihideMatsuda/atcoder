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
    #define MAX_N 2*  100000 + 5
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
    ll N, K;
    cin >> N >> K;
    while(K > 0){
        K--;
        if(N % 200 == 0) {
            N /= 200;
        } else {
            if(K > 0) {
                K--;
                N = N * 5 + 1;
            } else {
                N = N * 1000 + 200;
            }
        }
    }
    cout << N << endl;
}



int main(){
    solve();
    return 0;
}

