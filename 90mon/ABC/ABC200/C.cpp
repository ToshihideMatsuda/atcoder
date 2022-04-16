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
    ll N;
    cin >> N;

    vector<ll> R[200];

    rep(i,N) {
        ll A;
        cin >> A;
        R[A%200].push_back(A);
    }

    ll ans = 0;
    rep(i,200) {
        sort(R[i].begin(),R[i].end());
        rep(j, R[i].size()) {
            ans += R[i].size() - (j + 1);
        }
    }
    cout << ans << endl;
}



int main(){
    solve();
    return 0;
}

