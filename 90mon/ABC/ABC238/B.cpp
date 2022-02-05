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
vector<int> A;
vector<int> C;
    cin >> N;
    A.resize(N);
    rep(i,N) cin >> A[i];

    C.push_back(0);
    rep(i,N) {
        vector<int> next;
        for(auto r : C) {
            next.push_back((r + A[i]) % 360);
        }
        next.push_back(0);
        C = next;
    }

    C.push_back(360);

    sort(C.begin(), C.end());

    int maxdf = 0;
    reps(i, 1, C.size()) {
        int df = C[i] - C[i -1];

        maxdf = max(maxdf, df);
    }

    cout << maxdf << endl;

    

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
