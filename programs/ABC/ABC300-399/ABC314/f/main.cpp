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

#define MAX_N (4*100000+5)
using mint = modint998244353;

struct UnionFindTreeWithSize {

    vector<int> tree;  // 実態
                       // 正数:子, 負数:親(値は子の数)、0:未初期化
    vector<int> dep;   // unionfind木の深さ

    UnionFindTreeWithSize(int n): tree(n,0), dep(n,0){
	    for (int i = 0; i < n; i ++) {
	        insert(i);
	    }

    }

    void insert(int edge){
        tree[edge] = -1;
        dep[edge] = 1;
    }

    // rootを辿って同じものかを判定
    bool same (int e1, int e2)  {
        int x = root(e1);
        int y = root(e2);

        if(x == y) return true;
        return false;
    }

    // rootを辿って、深さに応じてくっつける
    void unionTree(int e1, int e2) {
        int x = root(e1);
        int y = root(e2);

        if(x == y) return;

        if(dep[x] >= dep[y] ) {
            tree[x] += tree[y]; //負数の要素をくっつける
            tree[y] = x;
            dep[y] ++;
        } else {
            tree[y] += tree[x]; //負数の要素をくっつける
            tree[x] = y;
            dep[x] ++;
        }
    }

    // treeの先を辿ってtreeにする
    int root(int e) {
        int r = tree[e];
        if(r < 0 ) { return e;} //負数が親
        else {
            tree[e] = root(r);
            return tree[e];
        }
    }

    int getSize(int e) {
        int r = root(e);
        return tree[r] * -1;
    }

    void setSize(int e, int t) {
        int r = root(e);
        tree[r] = t * -1;
    }

};

int main()
{
	ll N;
	cin >> N;

	vector<mint> ans(N+1,1);

	UnionFindTreeWithSize tree(MAX_N);

	vector<tuple<ll,mint, mint> > G[MAX_N];
	ll n = N+1;
	rep(i,N-1) {
		ll p, q;
		cin >> p >> q;

		ll left = tree.getSize(p);
		ll right = tree.getSize(q);
		ll all = left + right;
		
		G[n].push_back({tree.root(p),left,all});
		G[n].push_back({tree.root(q),right,all});
		tree.unionTree(n,p);
		tree.unionTree(n,q);

        tree.setSize(n,all);


		n++;
	}


	queue<pair<ll,mint>> Q;
	Q.push( { n-1, 0 });
	while(Q.size() > 0) {
		auto [q, p] = Q.front(); Q.pop();
		if(G[q].size() == 0){
			ans[q] = p;
		}
		for(auto [g, pg, all] :G[q]) {
            //cout << q << "->" << g <<":" << pg << "/" << all <<endl;
			Q.push({g, p + pg/ all});
		}
	}

	reps(i,1,N+1) {
		out0(ans[i].val())
		out0(" ")
	}




	return 0;
}