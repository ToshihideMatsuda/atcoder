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


ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}


void solve(){
    ll L, R;
    cin >> L >> R;

    ll d = R - L;

    while(true){
        for(ll l = L; l + d <= R; l++){
            if(gcd(l, l + d) == 1){
                cout << d << endl;
                return;
            }
        }
        d--;
    }

}




int main(){
    solve();
    return 0;
}

