#include <bits/stdc++.h>

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
    int N;
    cin >> N;
    vector<ll> x(N);
    rep(i,N) cin >> x[i];
    
    ll l0= 0, l2 = 0;
    double l1 = 0;

    rep(i,N) l0 += abs(x[i]);
    rep(i,N) l1 += x[i] * x[i];
    l1 = sqrt(l1);
    rep(i,N) l2  = max(l2,abs(x[i]));
    
    cout << l0 << endl;
    cout << setprecision(15) << l1 << endl;
    cout << l2 << endl;

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

