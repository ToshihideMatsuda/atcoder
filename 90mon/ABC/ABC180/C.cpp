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
    ll N;
    cin >> N;

    ll n = sqrt(N);
    map<ll, ll> mp;

    reps(i,1,n+1) 
        if(N % i == 0) {
            mp[i] = 1;
            mp[N/i] = 1;
        } 
    
    mp[N] = 1;

    for(auto it : mp) {
        cout << it.first << endl;
    }

    return;
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

