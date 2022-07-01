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

int dx[] = {1, 2,  1, 2, -1, -2,  -1, -2};
int dy[] = {2, 1, -2,-1,  2,  1,  -2, -1};


void solve(){
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    set<pair<int,int>> kouho1, kouho2;

    rep(i,8) {
        kouho1.insert({x1 + dx[i], y1 + dy[i]});
        kouho2.insert({x2 + dx[i], y2 + dy[i]});
    }

    for(auto xy: kouho1) {
        if(kouho2.count(xy) > 0) {
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
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
