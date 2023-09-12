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
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

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

int main()
{
    ll N, M, K; cin >> N >> M >> K;
    vector<ll> D(N+1,0);
    rep(i,M) {
        ll u, v; cin >> u >> v;
        D[u] ++;
        D[v] ++;
    }

    ll odd = 0, even = 0;
    reps(i,1,1+N) if(D[i] % 2 == 0) even++; else odd++;

    mint ans = 0;
    ll oddmin = 0;

    if(even == 0 && K % 2 == 1) {
        out(0)
        return 0;
    }

    for(int i = 0; i <= K; i += 2){
        if(K <= even + i) { 
            oddmin = i;
            break;
        }
    }


    for(int k = oddmin; k <= MIN(K,odd); k += 2) {
        ans += modComb(odd,k) * modComb(even, K-k);

    }

    out(ans.val())


	return 0;
}