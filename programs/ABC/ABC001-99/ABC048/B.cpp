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
    ll a, b, x;

    cin >> a >> b >> x;

    if(a == 0 & b == 0) {
        cout << 1 << endl;
    } else if(a == 0) {
        ll bb = b/x;
        ll aa = (a-1)/x;

        cout << bb + 1 << endl;
    } else {
        ll bb = b/x;
        ll aa = (a-1)/x;

        cout << bb - aa << endl;
    }

}



int main(){
    solve();
    return 0;
}
