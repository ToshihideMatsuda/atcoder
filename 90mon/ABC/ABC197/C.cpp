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
    #define MAX_N 100000 + 5
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
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i,N) cin >> A[i];

    ll ans = (1L << 60);
    rep(i, (1 << N)) {
        vector<int> OR;
        int cur = 0;
        rep(j,N) {
            cur = cur | A[j];
            if( (i & (1 << j)) > 0) {
                OR.push_back(cur);
                cur = 0;
            }
        }

        OR.push_back(cur);

        ll x = 0;
        rep(j,OR.size()) {
            x = x ^ OR[j];
        }
        ans = min(ans,x);
    }
    cout << ans << endl;

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

