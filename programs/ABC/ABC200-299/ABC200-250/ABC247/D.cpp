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
    int Q;
    cin >> Q;

    deque<pair<ll,ll>> DQ;

    rep(i,Q) {
        ll t = 0;
        cin >> t;
        if(t == 1) {
            ll x, c1;
            cin >> x >> c1;
            DQ.push_back({x,c1});
        } else {
            ll c2;
            cin >> c2;

            ll ans = 0;

            while(c2 > 0) {
                auto [x, c1] = DQ.front();DQ.pop_front();
                if(c2 >= c1) {
                    // all
                    ans += x * c1;
                    c2 = c2 - c1;
                } else { // c2 < c1
                    // part
                    ans += x * c2;
                    DQ.push_front({x, c1 - c2});
                    c2 = 0;
                }
            }
            cout << ans << endl;
        }
    }
}



int main(){
    solve();
    return 0;
}

