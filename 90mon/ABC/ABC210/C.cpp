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

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 



#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#if debug == true
    #define MAX_N 100 + 5
#else
    #define MAX_N 10000 + 5
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
    int N, K;
    cin >> N >> K;
    
    vector<int> c(N);
    rep(i, N) cin >> c[i];
    
    map<int,int> mp;
    rep(i, K) {
        mp[c[i]]++;
    }

    int ans = mp.size();

    int st=0,en=K;
    while(en < N) {
        if(mp[c[st]] == 1) {
            mp.erase(c[st++]);
        } else {
            mp[c[st++]]--;
        }
        
        mp[c[en++]]++;
        ans = max(ans, (int)mp.size());
    }

    cout << ans << endl;



}


int main(){
    solve();
    return 0;
}

