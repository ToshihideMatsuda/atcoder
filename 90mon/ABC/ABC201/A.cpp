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

vector<int> G[MAX_N];

void solve(){
    vector<int> A(3);
    rep(i,3) cin >> A[i];
    sort(A.begin(),A.end());

    if(A[0] - A[1] == A[1] - A[2])
        cout << "Yes" << endl;
    else
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

