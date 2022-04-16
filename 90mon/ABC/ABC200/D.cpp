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

    vector<ll> A(N);
    rep(i,N) cin >> A[i];

    vector<ll> R[200];

    reps(i, 1, 201) {
        vector<ll> B;
        ll idx =0;
        ll j = i;

        while(j > 0 && idx < N) {
            if(j & 1 == 1LL) {
                B.push_back(idx);
            }
            idx ++;
            j = j >> 1;
        }

        ll sum = 0;
        rep(i,B.size()) {
            sum += A[B[i]];
            sum %= 200;
        }
        if(R[sum] == B)  continue;
        if(R[sum].size() > 0) {
            cout << "Yes" << endl;

            cout << R[sum].size() << " ";
            rep(i,R[sum].size()) cout << R[sum][i] + 1 << " ";
            cout << endl;

            cout << B.size() << " ";
            rep(i,B.size()) cout << B[i] + 1 << " ";
            cout << endl;
            return;
        }
        else {
            R[sum] = B;
        }

    }

    NO();
}



int main(){
    solve();
    return 0;
}

