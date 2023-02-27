#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) MIN(a,MIN(b,c))
#define out(s) cout << s << endl;
#define out2(s) cout << s;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }



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

void solve() {
    ll N, K; cin >> N >> K;
    vector<ll> A(SIZE + 5);
    rep(i,N) {
        ll a; 
        cin >> a;
        A[a] ++;
    }

    ll ans =0;
    ll s = 0;

    ll h = 1;
    rep(k, SIZE) {
        ll n = k+1;
        ll tmp = modHomo(n, K-1);
        ans += tmp;
        ans %= MOD;
        if(A[k] ==0) {
            K--;
        }
        if(K==0) break;
    }
    out(ans);


}


int main()
{
  solve();
	return 0;
}