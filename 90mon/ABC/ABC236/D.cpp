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

#define MAX_N 100000 + 5
#define INF 1 << 28

ll N, M;

ll A[2*8][2*8];
bool check[2*8];
ll ans = 0;
unordered_map<int, ll> mp;

void dps(ll val) {

    bool end = true;
    int i = 0;
    rep(k, 2*N-1) {
        if(check[k] == false)
        {
            end = false;
            i = k;
            break;
        }
    }

    if(end)
    {
        ans = max(ans,val); 
        return;
    }


    reps(j,i+1,2*N) {
        if(check[j] == false) {
            check[i] = true;
            check[j] = true;
            dps(val^A[i][j]);
            check[i] = false;
            check[j] = false;
        }
    }

}

int main(){
    cin >> N;

    rep(i, 2*8) {
        check[i] = false;
    }

    rep(i, 2*N-1) {
        reps(j,i+1,2*N) {
            ll a;
            cin >> a;
            A[i][j] = a;
            A[j][i] = a;
        }
    }
    dps(0);
    cout << ans << endl;

    return 0;
}

//1033007587
//1073289207