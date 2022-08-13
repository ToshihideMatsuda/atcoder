#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) max(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) min(a,MIN(b,c))

#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5

ll N, M, E, Q;

vector<ll> G[MAX_N];


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

};


void solve() {
  cin >> N >> M >> E;
  vector<ll> U(E), V(E);
  rep(i,E)  cin >> U[i] >> V[i];

  cin >> Q;
  vector<ll> X(Q);
  set<ll> Xs;
  rep(i,Q) {
    cin >> X[i];
    X[i]--;
    Xs.insert(X[i]);
  }
  reverse(X.begin(),X.end());

  UnionFindTreeWithSize tree(MAX_N);
  rep(i,N+2) tree.insert(i);

  //全て切れた状態
  rep(i,E) if(!Xs.count(i)){
    if(U[i] > N && V[i] > N ) continue;
    if(U[i] > N) U[i] = N+1;
    if(V[i] > N) V[i] = N+1;

    tree.unionTree(U[i],V[i]);
  }

  vector<ll> ans;
  ans.push_back(tree.getSize(N+1) - 1);

  rep(i,Q) {
    ll u = U[X[i]], v = V[X[i]];
    if(u > N && v > N ) {
      ans.push_back(tree.getSize(N+1) - 1);
      continue;
    }
    if(u > N) u = N+1;
    if(v > N) v = N+1;

    tree.unionTree(u,v);
    ans.push_back(tree.getSize(N+1) - 1);
  }

  reverse(ans.begin(),ans.end());
  rep(i,ans.size()-1) cout << ans[i+1] << endl;

}


int main()
{
  solve();
	return 0;
}