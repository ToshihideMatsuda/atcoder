#include <bits/stdc++.h> 
#include <atcoder/all>
using namespace atcoder;
using namespace std;

typedef long long ll;
using mint = modint998244353;

long long const SIZE = (2*100000+5) * 4;

vector<mint> fact, fact_inv, inv;
/*  init_nCk :二項係数のための前処理
    計算量:O(n)
*/
bool init = false;
void initFact() {
    if(init) return ;
    fact.resize(SIZE + 5);

    fact[0] = fact[1] = 1;

    for (int i = 2; i < SIZE + 5; i++) {
        fact[i] = fact[i - 1] * i;
    }
    init = true;
    
}

mint modPerm(ll n, ll k) {
    initFact();
    return (fact[n] / fact[n-k]);
}

mint modComb(ll n, ll k) {
    initFact();
    if(k==0) return 1;
    mint a = modPerm(n, k);
    return (a / fact[k]);
}

// 重複組合せnHk = n+k-1Ck
// n個の箱にk個のボール（区別なし）を分ける方法
mint modHomo(ll n, ll k) {
    initFact();
    return modComb(n+k-1,k);
}
