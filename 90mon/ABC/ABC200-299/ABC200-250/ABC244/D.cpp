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
    /* BGR */
    vector<char> S(3), T(3);
    cin >> S[0] >> S[1] >> S[2];
    cin >> T[0] >> T[1] >> T[2];

    int tenchiS =0, tenchiT =0;
    
    rep(i,3) reps(j,i+1,3)  {
        if(S[j] < S[i]) 
            tenchiS++;
    }

    rep(i,3) reps(j,i+1,3)  {
        if(T[j] < T[i]) 
            tenchiT++;
    }

    if(tenchiS %2 == tenchiT %2) cout << "Yes" << endl;
    else cout << "No" << endl;

}
/*
R G B
R B G
*/



int main(){
    solve();
    return 0;
}

