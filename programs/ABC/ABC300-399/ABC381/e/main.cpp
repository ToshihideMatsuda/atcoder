#include <bits/stdc++.h> 
#include <atcoder/all>

using namespace atcoder;
using namespace std;
// 多倍長テンプレ（デバッグだとダメかも）

typedef long long ll;

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


#define INF  (2000000000000000001LL)
#define MINF (-2000000000000000001LL)
#define MOD 998244353

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


struct CalcTree {
    vector<tuple<ll, ll,ll>> tree; 
						// tree[x] = { [l,r),c };
						// 実態
                       	// 正数:子, 負数:親(値は子の数)、0:未初期化

    vector<ll> count; 
    vector<ll> dep;   	// unionfind木の深さ
	ll N = 0;

    CalcTree(ll n): tree(n), dep(n,0), count(n,0){
	    for (ll i = 0; i < n; i ++) {
	        insert(i);
	    }
		N = n;
    }

    void insert(ll edge){
        tree[edge] = {edge, edge+1, edge};
		count[edge] = 1;
        dep[edge] = 1;
    }

    // rootを辿って、深さに応じてくっつける
    void unionTree(ll e1, ll e2) {
        auto [l1, r1, c1] = root(e1);
        auto [l2, r2, c2] = root(e2);

        if(r1 == l2 && c1 == c2) {
			tree[e1] = {l1,l1,-1};
			tree[e2] = {l1,l1,-1};
			tree[l1] = {l1,r2,c1};
		} else if(r2 == l1 && c1 == c2) {
			tree[e1] = {l2,l2,-1};
			tree[e2] = {l2,l2,-1};
			tree[l2] = {l2,r1,c1};
		} 
    }
    // rootを辿って、深さに応じてくっつける
    void oneQuery(ll x, ll c) {
        auto [l, r, c_old] = root(x);
		count[c_old] -= r-l;
		tree[l] = {l,r,c};
		count[c] += r-l;

		if(1 <= l-1) unionTree(l,l-1);
		if(r < N)    unionTree(r-1,r);
    }

	ll twoQuery(ll c) {
		return count[c];
	}

    // treeの先を辿ってtreeにする
    tuple<ll,ll,ll> root(ll x) {
        auto [l, r, c] = tree[x];
		if(c == -1) {
			auto [lr,rr,cr] = root(l);
			tree[x] = {lr,lr,-1};
			return {lr,rr,cr};
		} 
		else {
			return tree[x];
		}
    }

};

int main()
{

	ll N; cin >> N;
	ll Q; cin >> Q;
	CalcTree calc(N+1);
	while(Q--) {
		ll t; cin >> t;
		if(t == 1) {
			ll x, c; cin >> x >> c;
			calc.oneQuery(x,c);
		} else { 
			ll c; cin >> c;
			ll count = calc.twoQuery(c);
			out(count)
		}
	}


	return 0;
}