#include <bits/stdc++.h> 
#include <atcoder/all>
using namespace atcoder;
using namespace std;

using mint = modint998244353;
mint binom[5010][5010];
void initBinom() {
    for (int i = 0; i < 5010; i++) {
        binom[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            binom[i][j] = binom[i - 1][j - 1] + binom[i - 1][j];
        }
    }
}


int main() {
    initBinom();
    return 0;
}