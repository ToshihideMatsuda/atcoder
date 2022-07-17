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
    ll N, a, b; cin >> N >> a >> b;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    sort(A.begin(),A.end(),greater<ll>());

    ll lb = -1, ub = 1L << 60;
    while(ub - lb > 1) {
        ll mid = (lb + ub) / 2;
       //mid = 5;
        ll ob = 0;
        ll ok = 0;
        rep(i,N) {
            if(A[i] >= mid) {
                ok++;
                ob += (A[i] - mid)/b;
            }
            else{
                ob -= (mid - A[i]-1)/a+1;
                if(ob >= 0) ok++;
            }
        }


        if(ok >= N ){
            lb = mid;
        } else {
            ub = mid;
        }

    }

    cout << lb << endl;
}

int main(){
    solve();
	
    return 0;
}
