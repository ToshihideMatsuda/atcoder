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

vector<int> A;
int N;


void solve(){
    vector<int> x(4), y(4);
    rep(i,3) cin >> x[i] >> y[i]; 
    if(x[0] == x[1]) 
        x[3] = x[2];
    else if(x[1] == x[2])
        x[3] = x[0];
    else if(x[2] == x[0])
        x[3] = x[1];

    if(y[0] == y[1]) 
        y[3] = y[2];
    else if(y[1] == y[2])
        y[3] = y[0];
    else if(y[2] == y[0])
        y[3] = y[1];

        cout << x[3] << " " << y[3] << endl;


}



int main(){
    solve();
    return 0;
}

