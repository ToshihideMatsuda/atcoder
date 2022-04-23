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
    int N, x0, y0, xn2, yn2;
    cin >> N >> x0 >> y0 >> xn2 >> yn2;

    double xo = (xn2+x0)/2.0;
    double yo = (yn2+y0)/2.0;

    double S = (2 * M_PI) / N;

    double cosS = cos(S);
    double sinS = sin(S);


    double x0_r = x0 - xo;
    double y0_r = y0 - yo;

    double x1_r = x0_r * cosS  - y0_r * sinS;
    double y1_r = x0_r * sinS  + y0_r * cosS;

    double x1 = x1_r + xo;
    double y1 = y1_r + yo;

    cout << setprecision(15) << x1 << " " << setprecision(15) << y1 << endl;


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

