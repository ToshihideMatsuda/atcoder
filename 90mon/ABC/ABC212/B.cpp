#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <numeric>

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
    #define MAX_N 2*100000 + 5
#endif


void solve(){
    int x;
    cin >> x;
    vector<int> X(4);

    X[0] = x/1000;
    X[1] = (x - X[0]*1000)/100;
    X[2] = (x - X[0]*1000 - X[1]*100)/10;
    X[3] = (x - X[0]*1000 - X[1]*100 - X[2]*10);

    bool weak = true;
    rep (i, 3) {
        if(X[i] == X[i+1]) 
            continue;
        weak = false;
    }
    if(weak){
       cout << "Weak" <<endl; 
       return;
    }

    weak = true;
    rep(i,3) {
        
        if(X[i] == 9 && X[i+1] == 0) 
            continue;
        if(X[i+1] -X[i] == 1) 
            continue;
        
        weak = false;
    }

    if(weak){
       cout << "Weak" <<endl; 
       return;
    }
    cout << "Strong" <<endl; 
    


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
