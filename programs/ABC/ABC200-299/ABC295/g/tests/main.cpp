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
#define out0(s) cout << s;
#define out(s) out1(s)
#define out1(s) cout << s << endl;
#define out2(s,t) cout << s << t << endl;
#define out3(s,t,r) cout << s << t << r << endl;
#define out4(s,t,r,u) cout << s << t << r << u << endl;
#define out5(s,t,r,u,o) cout << s << t << r << u << o << endl;
#define outd(s) cout << setprecision(15) << s << endl;
#define pb(s) push_back(s)

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N 10//(2*100000+5)
vector<ll> G[MAX_N];
vector<ll> H[MAX_N];
ll X[MAX_N+1];


bool ck[MAX_N]; 
void clear() { rep(i,MAX_N) ck[i] = false; }

ll dfs(ll p) {
	if(ck[p] == true) return X[p];
	ck[p] = true;
	ll x = p;
	for(auto g:G[p]) {
		if(ck[g] == false) {
			x = MIN(dfs(g),x);
		}
	}
	X[p] = x;
	return x;
} 

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


ll dfs2(ll p) {
	if(ck[p] == true) return X[p];
	ck[p] = true;
	ll x = p;
	for(auto g:H[p]) {
		if(ck[g] == false) {
			x = MIN(dfs(g),x);
		}
	}
	X[p] = x;
	return x;
} 

int main()
{
	ll N; cin >> N;

	UnionFindTree<ll> tree;
	reps(i,1,N+1) {
	    tree.insert(i);
	}

	reps(i,1,N) {
		ll p; cin >> p;
		G[p].push_back(i+1);
		H[i+1].push_back(p);
	}

	reps(i,1,N+1) dfs(i);


	ll Q; cin >> Q;
	rep(i,Q) {
		ll t; 
		cin >> t;
		if(t == 1) {
			ll u, v; cin >> u >> v;


		} else {
			ll x; cin >> x;
			out(MIN(X[x],tree.root(x)));
		}
	}
	

	return 0;
}