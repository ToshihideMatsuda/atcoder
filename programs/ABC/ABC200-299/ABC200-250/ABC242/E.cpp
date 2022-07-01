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

#include <bits/stdc++.h> 

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

void OK() {
  cout << "Yes" << endl;
  exit(0);
}

int dp[1000000+5][10];

/*
ACCCAAAA

1 * 2 * 26
1 * 1 * 3
-1
*/
void solve(){
    int T;
    cin>> T;
    vector<int> ans;
    rep(_,T) {
        int N;
        string S;
        cin >> N >> S;
        
        int inside = 1;
        bool sameIsOk = true;

        rep(i, (N+1) /2) {
            char c = S[i];
            int cnt = c - 'A' + 1;
            
            if(c != 'A') {
                inside = (inside * cnt) % MOD + (cnt - 1)  %MOD;
            }

            if(S[i] > S[N-1-i]) sameIsOk = false;
        }

        int ansE = (inside + sameIsOk ? 1 : 0) % MOD;
        ans.push_back(ansE);
    }

    rep(i,T) cout << ans[i] << endl;
    
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


