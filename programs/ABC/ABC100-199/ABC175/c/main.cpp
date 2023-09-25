#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>


#define rep(i,n)     for(int i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(int i = m; i < n; i++ ) 


typedef long long ll;
using namespace std;

#define MAX_N 2*100000 + 5
#define INF 1 << 28

int main(){
    ll X,K,D;
    cin >> X >> K >> D;

    X = abs(X);


    // case1 X > 0; X-D*K > 0 => X-D*K
    if( X / D > K ) {
        cout << X-D*K  << endl;
    } else {
        //case3 単振動する
        ll minPlus = X/D;
        ll minAns  = X - minPlus * D;

        ll r = K - minPlus;
        ll ans = r % 2ll == 0ll ? 
                    minAns : D - minAns;
        
        cout << ans << endl;
    }


    return 0;
}