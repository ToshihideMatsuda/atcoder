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
/*
CBBAACCCCC
5
57530144230160008 659279164847814847
29622990657296329 861239705300265164
509705228051901259 994708708957785197
176678501072691541 655134104344481648
827291290937314275 407121144297426665

*/
    string S;
    int Q;
    cin >> S >> Q;

    vector<char> ans;
    rep(_,Q){
        ll t, k;
        cin >> t >> k;
        k --;

        //s^t = s.size()*2^t乗の長さ
        //k = k0 * 2^t + k1
        vector<ll> ks;
        ll k0 = k;
        rep(i, t) {
            k0 /= 2;
            if(k0 == 0) break;
        }
        
        ll k1 = (k0 > 0) ? k % k0 : k;

        char c = S[k0];


        int k1keta = 0, k1tmp = k1;
        while(k1tmp > 0) { k1tmp = k1tmp >> 1; k1keta++; }

        if(t > k1keta) {

            rep(_, (t - k1keta) % 3) {
                c = c == 'A' ? 'B' : 
                    c == 'B' ? 'C' : 'A' ;
            }
            t = k1keta;
        }

        
        for(int keta = t; keta > 0; keta--) {
            string s = c == 'A' ? "BC" : 
                       c == 'B'  ? "CA" : "AB" ;

            if( ( (k1 >> keta) & 1) == 1 ) {
                c = s[1];
            }else {
                c = s[0];
            }
        }
        ans.push_back(c);
    }

    rep(i,ans.size()) cout << ans[i] << endl;

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

