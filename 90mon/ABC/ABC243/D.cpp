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

#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#if debug == true
    #define MAX_N 100 + 5
#else
    #define MAX_N 2*100000 + 5
#endif

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}
void UNSOLVABLE() {
  cout << "UNSOLVABLE" << endl;
}

void solve(){
    ll N, X;
    string S;
    cin >> N >> X >> S;

    int i = 1;

    deque<char> dq;
    deque<char> dq2;

    //endmark
    dq2.push_back('$');

    rep(i,S.size()) {
        dq.push_back(S[i]);
    }

    while(dq.size() > 0) {
        char dq2back = dq2.back();
        char dqfront  = dq.front();

        if((dq2back == 'R' || dq2back == 'L') && 
            dqfront == 'U') {
            //消す
            dq2.pop_back();
        }
        else {
            dq2.push_back(dqfront);
        }
        dq.pop_front();
    }

    rep(i,dq2.size()) {
        if(dq2[i] == 'U') X = X/2;
        else if(dq2[i] == 'L') X = X*2;
        else if(dq2[i] == 'R') X = X*2+1;
    }

    cout << X << endl;
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


