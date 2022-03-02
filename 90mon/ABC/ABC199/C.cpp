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

void solve(){
    int N, Q;
    string S;
    cin >> N >> S >> Q;

    bool chng = false;
    
    rep(i,Q){
        int t, A, B;
        cin >> t >> A >> B;
        if(t == 1) {
            int A2 = ((A-1) + (chng? N : 0) ) % (2*N);
            int B2 = ((B-1) + (chng? N : 0) ) % (2*N);
            swap(S[A2], S[B2]);
        } else if (t == 2) {
            chng = !chng;
        }
    }
    string T(S.begin(),   S.begin() + N);
    string U(S.begin()+N, S.end());
    if(chng) {
        cout << U <<  T << endl;
        return;
    } else {
        cout << T <<  U << endl;
        return;
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

