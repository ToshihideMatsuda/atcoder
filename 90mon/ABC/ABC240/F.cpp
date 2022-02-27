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
    int T;
    cin >> T;
    rep(i,T) {
        int N,M;
        ll B = 0, A = 0, maxA =  MINF_LL;
        cin >> N >> M;
        rep(i,N) {
            ll x,y;
            cin >> x >> y;
            if(i == 0)
                maxA = x;
            ll nextB = B + x * y;
            ll nextA = A + (B * y) + (x * y * (y+1))/2;
            if(B > 0 && nextB < 0) {
                ll z = B / abs(x);
                ll supA = A + (B * z + (x * z * (z+1))/2 );
                maxA = max(maxA, supA);
            }
            else if(nextA > A) {
                maxA = max(maxA, nextA);
            }
            A = nextA;
            B = nextB;
        }
        cout << maxA << endl;
    }


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
