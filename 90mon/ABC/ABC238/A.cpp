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

#if debug == true
    #define MAX_N 100 + 5
#else
    #define MAX_N 2 * 100000 + 5
#endif


void solve(){
    int N;
    int power = 1;
    cin >> N;
    if(N > 10) {
        cout << "Yes" << endl;
        return ;
    }

    rep(i,N) power *=2;
    

    bool ok = power > N*N;
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
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
