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
    #define MAX_N 10 + 5
#else
    #define MAX_N 100000 + 5
#endif

int N;
string S;

void solve(){
    cin >> N >> S;
    vector<int> L, R;

    rep(i,N) {
        if(S[i] == 'L') {
            R.push_back(i);
        } else if(S[i] == 'R') {
            L.push_back(i);
        }
    }
    reverse(R.begin(),R.end());

    rep(i,L.size()) cout << L[i] << " ";
    cout << N << " ";
    rep(i,R.size()) cout << R[i] << " ";
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
