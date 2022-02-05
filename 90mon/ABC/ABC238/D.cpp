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
#define MOD 998244353

/*
4090959091 // 100000 
40914090   // 10000
998244353

---debugMode---
53500
987104341
487982164


998244353
100000
4090959091
---debugMode---
53800
1000199791

*/
#if debug == true
    #define MAX_N 100 + 5
#else
    #define MAX_N 2 * 100000 + 5
#endif


void solve(){
    int T;
    cin >> T;

    rep(i,T) {
        ll a,s;
        cin >> a >> s;

        if(s < a) {
            cout << "No" << endl;
            continue;
        }
        else {
            bool ketaAgari = false;
            while(s > 0) {
                int bitS = (s & 1);
                int bitA = (a & 1);

                if(bitS ==0 && bitA ==0) {
                    if(ketaAgari)
                    {
                        ketaAgari = true;
                    }
                }
                else if(bitS ==0 && bitA ==1){
                    if(ketaAgari)
                    {
                        cout << "No" << endl;
                        goto next;
                    }
                    ketaAgari = true;
                }
                else if(bitS ==1 && bitA ==0){
                    ketaAgari = false;
                }
                else if(bitS ==1 && bitA ==1){
                    if(!ketaAgari)
                    {
                        cout << "No" << endl;
                        goto next;
                    }
                    ketaAgari = true;
                }

                s = s >> 1;
                a = a >> 1;
            }
            cout << "Yes" << endl;
            next:
            continue;
        }

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
