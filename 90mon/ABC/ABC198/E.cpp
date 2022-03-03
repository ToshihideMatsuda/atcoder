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

    string S[3];
    cin >> S[0] >> S[1] >> S[2];

    vector<int> ptn(10);
    rep(i,10) ptn[i] = i;

    string SS;
    SS = S[0] + S[1] + S[2];
    int mp[27];
    int cnt = 0;
    rep(i, 27) mp[i] = -1;
    rep(i,SS.size()) {
        if(mp[SS[i] - 'a'] == -1) mp[SS[i] - 'a'] = cnt ++;
    }

    if(cnt >= 11) {
        UNSOLVABLE();
        return;
    }

    do {
        ll s[3];
        s[0] = 0;s[1] = 0;s[2] = 0;
        rep(i,3) {
            ll keta = 1;
            if(ptn[mp[S[i][0] - 'a']] == 0) goto next;
            rep(j,S[i].size()) {
                s[i] += (ptn[mp[S[i][S[i].size() - 1 - j] - 'a']] * keta);
                keta *= 10;
            }
            if(s[0] + s[1] == s[2]) {
                cout << s[0] << endl << s[1] <<endl << s[2] << endl;
                return;
            }
        }

        next:
        continue;
    } while(next_permutation(ptn.begin(), ptn.end()));
    UNSOLVABLE();
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

