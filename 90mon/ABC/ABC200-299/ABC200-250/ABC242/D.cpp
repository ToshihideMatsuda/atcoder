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

char next(char ch, int i) {
    if ( i == 0 || i == 1 || i == 2) {
        return (char)(((ch - 'A') + i)%3 + 'A') ;
    } else {
        cout << "Exception" << endl;
        exit(1);
    }
}

string S;
char f(ll t, ll k) {
    if(t == 0) return S[k];
    if(k == 0) return next(S[k],t % 3);
    else if (k % 2 == 0) return next(f(t-1, k/2), 1);
    else if (k % 2 == 1) return next(f(t-1, k/2), 2);
    return '$';
}

void solve(){
    int Q;
    cin>> S >> Q;
    vector<char> ans;
    rep(_,Q) {
        ll t, k;
        cin >> t >> k;
        k--;
        ans.push_back(f(t,k));
    }

    rep(i,Q) cout << ans[i] << endl;
    
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


