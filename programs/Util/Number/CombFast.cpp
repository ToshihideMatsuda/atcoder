#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;
#define MOD 998244353

long long const SIZE = (2*100000+5) * 4;

vector<long long> fact, fact_inv, inv;
/*  init_nCk :二項係数のための前処理
    計算量:O(n)
*/
bool init = false;
void initFact() {
    if(init) return ;
    fact.resize(SIZE + 5);
    fact_inv.resize(SIZE + 5);
    inv.resize(SIZE + 5);

    fact[0] = fact[1] = 1;
    fact_inv[0] = fact_inv[1] = 1;
    inv[1] = 1;

    for (int i = 2; i < SIZE + 5; i++) {
        fact[i] = fact[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD % i] * (MOD / i) % MOD;
        fact_inv[i] = fact_inv[i - 1] * inv[i] % MOD;
    }
    init = true;
    
}

ll modPerm(ll n, ll k) {
    initFact();
    return (fact[n] * fact_inv[n-k]) % MOD;
}

ll modComb(ll n, ll k) {
    initFact();
    if(k==0) return 1;
    ll a = modPerm(n, k);
    return (a * fact_inv[k]) % MOD;
}

// 重複組合せnHk = n+k-1Ck
// n個の箱にk個のボール（区別なし）を分ける方法
ll modHomo(ll n, ll k) {
    initFact();
    return (modComb(n+k-1,k)) % MOD;
}
