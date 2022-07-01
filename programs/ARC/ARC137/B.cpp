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
    cin >> N;
    A.resize(N);
    rep(i,N) cin >> A[i];

    int cursol = 0;
    int peak =0, bottom = 0;

    int maxPoint =0, minPoint = 0;

    rep(i, N) {
        //cout << "cursol = " << cursol  << ", peak = " << peak   << ", bottom = " << bottom  << ", maxPoint = " << maxPoint  <<  ", minPoint = " << minPoint << endl;
        if(A[i] == 0) { cursol --;}
        else { cursol ++;}

        peak   = max(peak, cursol);   //  1の個数 - 0の個数、の最大値
        bottom = min(bottom, cursol); //  1の個数 - 0の個数、の最小値

        maxPoint  = max(maxPoint, cursol - bottom);
        minPoint  = min(minPoint, cursol - peak);
    }        
    //cout << "cursol = " << cursol  << ", peak = " << peak   << ", bottom = " << bottom  << ", maxPoint = " << maxPoint  <<  ", minPoint = " << minPoint << endl;


    cout << maxPoint - minPoint + 1 << endl;

}



int main(){
    solve();
    return 0;
}

