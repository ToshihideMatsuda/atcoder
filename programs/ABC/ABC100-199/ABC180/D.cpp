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
    ll X, Y, A, B;
    cin >> X >> Y >> A >> B;
    ll ans = 0;

    while(( X < (X + B) / A ) && X < Y / A) {
        ll AA = A, preAA = 1;
        ll cnt = 1, preCnt = 0;
        while(( X  < (X + B)/AA) && X < Y / AA) {
            preAA = AA;
            preCnt = cnt;
            AA *= AA;
            cnt *= 2;
        }
        X *= preAA;
        ans += preCnt;
    }

    if(X < Y)  {
        if((Y - X) % B == 0) {
            ans += ((Y - X) / B - 1);
        }
        else {
            ans += (Y - X) / B;
        }
    }
    cout << ans << endl;


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

