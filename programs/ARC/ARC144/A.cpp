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
#define MOD 998244353

void solve() {
    ll N; cin >> N;
    ll M = N * 2;
    string x = "";

    while(N > 4) {
        x = x + "4";
        N -= 4;
    }
    if(N > 0) {
        x = to_string(N) + x;
    }

    cout << M << endl;
    cout << x << endl;


}

int main(){
    solve();
	
    return 0;
}
