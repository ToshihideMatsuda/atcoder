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
    int H, W, X, Y;
    cin >> H >> W >> X >> Y;
    X --; Y --;

    string S[H];
    rep(i, H) cin >> S[i];

    int cnt = 1;

    reps(i, 0, X) {
        if(S[X-1-i][Y] == '#') break;
        cnt ++;
    }
    
    reps(i, X+1, H) {
        if(S[i][Y] == '#') break;
        cnt ++;
    }


    reps(i, 0, Y) {
        if(S[X][Y-1-i] == '#') break;
        cnt ++;
    }
    
    reps(i, Y+1, W) {
        if(S[X][i] == '#') break;
        cnt ++;
    }

    cout << cnt << endl;

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

