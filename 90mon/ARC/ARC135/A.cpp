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

#if debug == true
    #define MAX_N 100 + 5
#else
    #define MAX_N 2 * 100000 + 5
#endif


ll X;
unordered_map<ll, pair<ll,int>> mp;

void calc(ll x) {

    if(x <= 4) {
        mp[x] = {x,1};
        return;
    }

    if(mp.count(x)) {
        mp[x] = {mp[x].first, 1};
        return;
    }

    ll low = x/2;
    calc(low);


    ll high = x%2 == 1 ? low+1 : low;
    if(x%2 == 1) {
        calc(high);
    }

    ll ans = 1;
    int cntLow = mp[low].second;
    int cntHigh = mp[high].second;

    while(cntLow > 0) {
        ans *= mp[low].first;
        ans %= MOD;
        cntLow--;
    }
    while(cntHigh > 0) {
        ans *= mp[high].first;
        ans %= MOD;
        cntHigh--;
    }

    mp[x] = { ans, 1 };

    return;
}

void solve(){
    cin >> X;
    calc(X);
    cout << mp[X].first << endl;
    return;
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
