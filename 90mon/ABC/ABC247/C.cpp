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

string S[17];

void calc(int n){
    if(n == 1) {
        S[1] = "1";
        return;
    }

    if(S[n].size() == 0) calc(n-1);
    S[n] = S[n-1] + " " + to_string(n)  + " " + S[n-1];

}

void solve(){
    int N;
    cin >> N;
    S[0] = "";
    calc(N);

    cout << S[N] << endl;
}



int main(){
    solve();
    return 0;
}

