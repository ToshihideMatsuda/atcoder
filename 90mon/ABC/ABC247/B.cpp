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
    ll N;
    cin >> N;
    vector<string> s(N), t(N);
    rep(i,N){
        cin >> s[i] >> t[i];
    }

    rep(i,N) {
        bool sok = true;
        bool tok = true;
        rep(j,N) {
            if(i == j) {
                continue;
            }

            if(s[i] == s[j] || s[i] == t[j]) sok = false;
            if(t[i] == s[j] || t[i] == t[j]) tok = false;
        }

        if( sok || tok ) continue;
        NO();
    }

    YES();    
}



int main(){
    solve();
    return 0;
}

