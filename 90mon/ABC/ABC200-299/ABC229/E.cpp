#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define max(a,b)   (a>b?a:b)
#define max3(a,b,c) max(a,max(b,c))
#define min(a,b)   (a<b?a:b)
#define min3(a,b,c) min(a,min(b,c))


#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5

vector<int> G[MAX_N];


template<typename T>
struct UnionFindTree {

    unordered_map <T,T> tree;  // T -> TのUnionTreeの実態
    unordered_map <T,int>dep; // unionfind木の深さ

    UnionFindTree() {}

    void insert(T edge){
        tree[edge] = edge;
        dep[edge] = 1;
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
int main()
{
	int n,m;
	cin>>n>>m;
	
	
	rep(i,m) {
		int a,b;
		cin >> a >> b;
        a--;
        b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	int ans[n+1];
	ans[n]=0;
	UnionFindTree<ll> d;
	
	for(int v=n-1; v>-1; v--){
		set<int> s;
        
        d.insert(v);

		for(auto u: G[v] ) if( u > v ) s.insert(d.root(u));

        if(s.size()==0){
		    ans[v]=ans[v+1]+1;
            continue;
		} else {
            ans[v] = ans[v+1] -(s.size() - 1);
		    for(auto u: G[v]) if( u > v ) d.unionTree(v,u);
        }
	}
	
    reps(i, 1, n+1) cout << ans[i] <<endl;
	
	
	
	return 0;
}