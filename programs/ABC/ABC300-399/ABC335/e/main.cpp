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
#define out(s) cout << s << endl;
#define out0(s) cout << s;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N (2*100000+5)

using mint = modint998244353;

template<typename T>
struct UnionFindTree {

    unordered_map <T,T> tree;  // T -> TのUnionTreeの実態
    unordered_map <T,int>dep; // unionfind木の深さ

    UnionFindTree() {}

    void insert(T edge){
        tree[edge] = edge;
        dep[edge] = 1;
    }
    
    bool exist(T edge){
        return tree.count(edge) > 0;
    }

    // rootを辿って同じものかを判定
    bool same (T e1, T e2)  {
        T x = root(e1);
        T y = root(e2);

        if(x== y) return true;
        return false;
    }

    // rootを辿って、深さに応じてくっつける
    void unionTree(T e1, T e2) {
        T x = root(e1);
        T y = root(e2);

        if(x== y) return;

        if(dep[x] >= dep[y] ) {
            tree[y] = x;
            dep[y] ++;
        } else {
            tree[x] = y;
            dep[x] ++;
        }
    }

    // treeの先を辿ってtreeにする
    T root(T e) {
        T r = tree[e];
        if(r == e) { return r;}
        else {
            tree[e] = root(r);
            return tree[e];
        }
    }

};

vector<pair<ll,ll>> G[MAX_N];
vector<pair<ll,ll>> H[MAX_N];
vector<ll> A;
vector<ll> dp;
UnionFindTree<ll> uft;

void dfs(ll p, set<ll>& S) {
	if(G[p].size() == 0) return;

	if( !(A[p] <= G[p].back().first) ) {
		return;
	}

	ll s = 0, e = G[p].size() - 1;

	if( G[p][0].first < A[p] ) {
		ll lb = 0, ub = e;
		while(ub - lb > 1) {
			ll mid = (ub + lb) / 2;
			if(A[p] <= G[p][mid].first ) ub = mid;
			else lb = mid;
		}
		s = ub;
	}

	for(ll i = s; i<= e; i ++) {
		auto [_, g] = G[p][i]; 
		if(A[p] <= A[g]){
			bool contains = S.count(A[g]);
			if(contains == false) {
				S.insert(A[g]);
			}

			if(dp[g] < S.size()) {
				dp[g] = S.size();
				dfs(g, S);
			}

			if(contains == false) {
				S.erase(A[g]);
			}
		}
	}

}

int main()
{
	
	ll N, M; cin >> N >> M;
	A.resize(N+1);
	dp.resize(N+1);
	
	rep(i,N) {
		cin >> A[i+1]; 
		uft.insert(i+1);
	}

	rep(i,M) {
		ll u, v; cin >> u >> v;
		if(A[v] < A[u]) {
			G[v].push_back({A[u], u});
		} else if(A[u] < A[v]) {
			G[u].push_back({A[v], v});
		} else {
			uft.unionTree(u,v);
		}
	}

	reps(i,N+1) {

	}



	rep(i,N+1) if(G[i].size() >= 2) {
		sort(G[i].begin(), G[i].end());
	}

	dp[uft.root(1)] = 1;
	
	set <ll> s =  { A[1] };
	dfs(uft.root(1), s);

	out(dp[N])
	
	return 0;
}
