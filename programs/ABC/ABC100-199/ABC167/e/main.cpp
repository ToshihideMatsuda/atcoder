#include <bits/stdc++.h> 
#include <atcoder/all>
using namespace atcoder;
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
#define out0(s) cout << s;
#define out(s)  cout << s << endl;
#define outd(s) cout << setprecision(15) << s << endl;
#define pb(s) push_back(s)
/*
	vector<ll> X = {4,7,3,1,7,9,4};
	SORT(X, <)
	OUT(X,",") //1,3,4,4,7,7,9,

	SORT(X, >)
	OUT(X," ") //9 7 7 4 4 3 1
*/
#define SORT(A,R) std::sort((A).begin(),(A).end(), [](auto const& x, auto const& y) { return x R y; });
#define OUT(A,separate) for(auto a : A) { cout << a << separate; }


#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N (2*100000+5)

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


using mint = modint998244353;


int main()
{
	ll N, M, K; cin >> N >> M >> K;
	vector<mint> powM_1(N+5);
	powM_1[0] = 1;
	reps(i,1,N+5) powM_1[i] = powM_1[i-1] * (M-1);

	mint ans = 0;
	rep(k,K+1) {
		ll c = modComb(N-1,k);
		ans += M * c * powM_1[N-1-k];
	}
	out(ans.val())

	return 0;
}