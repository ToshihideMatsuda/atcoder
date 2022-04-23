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

int F[MAX_N] ;
bool checked[MAX_N] ;

void solve(){
    ll N;

    cin >> N;

    vector<ll> P(N), Q(N);
    rep(i, N) cin >> P[i];
    rep(i, N) cin >> Q[i];

    ll PQ[MAX_N];
    rep(i, N) PQ[P[i]] = Q[i];

    F[1] = 1;
    if(N >= 2) F[2] = 3;
    reps(i, 3, N+1) 
    {
        F[i] = F[i-1] + F[i-2];
        F[i] %= MOD;
    }

    ll ans = 1;
    rep(i,N) {
        ll p = P[i];
        if(checked[p] == false) {
            ll n = 0;
            while(checked[p] == false) {
                n ++;
                checked[p] = true;
                p = PQ[p];
            }
            ans *= F[n];
            ans %= MOD;
        }
    }

    cout << ans << endl;
}



int main(){
    solve();
    return 0;
}

