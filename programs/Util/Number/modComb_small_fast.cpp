#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
#define MOD 998244353

//nCr のnの最大値
const ll MAX = 2*100000;       // 2*10^5 
// const ll MAX =  4*10000000; // 1858msec ACを確認  
bool initialized = false;
vector<ll> fac,finv,inv;
void init() {
    fac.resize(MAX);
    finv.resize(MAX);
    inv.resize(MAX);
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    for(int i=2; i<MAX; i++){
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = MOD-MOD/i*inv[MOD%i]%MOD;
        finv[i] = finv[i-1]*inv[i]%MOD;
    }
}
ll modComb(ll n, ll r){
    if (initialized == false) { 
      init();
      initialized = true;
    }
    if(n<r || n<0 || r<0) return 0;
    return fac[n]*finv[r]%MOD*finv[n-r]%MOD;
}
 