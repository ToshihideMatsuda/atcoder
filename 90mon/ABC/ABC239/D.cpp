#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>

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
    #define MAX_N 2 * 100000 + 5
#endif

void solve(){

    bool prime[201];
    
    prime[0] = false;
    prime[1] = false;
    prime[2] = true;

    for(int i = 3; i < 201; i++){
        bool ok = true;
        for(int j = 2; j < i; j++){
            if(i % j == 0) {
                prime[i] = false;   
                ok = false;
                break;
            }
        }       
        if(ok) prime[i] = true;
    }

    int A, B, C, D;
    cin >> A >> B >> C >> D;

    for(int t = A; t <= B; t++){
        bool next = false;
        for(int a = C; a <= D; a++) {
            if(prime[t+a]) {
                next = true;
                break;
            }
        }
        if(next) {
            continue;
        } else {
            // Takahashi
            cout << "Takahashi" << endl;
            return;
        }
    }

    cout << "Aoki" << endl;

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
