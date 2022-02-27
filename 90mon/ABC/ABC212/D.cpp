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
    ll Qs;
    cin >> Qs;

    priority_queue<
        pair<ll,ll>, 
        vector<pair<ll,ll>>, 
        greater<pair<ll,ll>>> Q;
    vector<ll> R;
    R.push_back(0);
    rep(_, Qs) {
        ll q,x;
        cin  >> q;
        if(q == 1) {
            cin >> x;
            x = x - R.back();
            Q.push({x, R.size() - 1});
        } else if(q == 2) {
            cin >> x;
            R.push_back(R.back() + x);
        } else {
            pair<ll,ll> q = Q.top();Q.pop();
            ll ans = (q.first + R[q.second]) + (R.back() - R[q.second]);
            cout << ans << endl; 
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


/*
16
1 3
1 5
1 2
2 2
1 1
1 3
1 8
2 1
1 4
3
3
3
3
3
3
3
*/