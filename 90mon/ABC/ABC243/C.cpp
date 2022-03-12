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

vector<int> G[MAX_N];

void solve(){
    int N;
    cin >> N;
    unordered_map<int,vector<pair<int,int>>> XYN;
    set<int> Y;
    rep(i,N) {
        int x, y;
        cin >> x >> y;
        Y.insert(y);
        XYN[y].push_back({x,i});
    }
    string S;
    cin >> S;

    for(int y : Y) {
        vector<pair<int,int>> XN = XYN[y];
        
        int minR = INF, maxL = -1;
        for(pair<int,int> xn : XN) {
            if(S[xn.second] == 'R') {
                minR = min(minR,xn.first);
            } else {
                maxL = max(maxL,xn.first);
            }
        }
        if(minR <= maxL) {
            cout << "Yes" << endl;
            return;
        }


    }

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


