#include <bits/stdc++.h> 
#include <unordered_map>
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

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}


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
    ll N, M; cin >> N >> M;
    vector<ll> A(M), B(M);
    rep(i,M){
         cin >> A[i] >> B[i];
         A[i]--; B[i]--;
    }

    UnionFindTreeWithSize tree(N);
    rep(i,N)tree.insert(i);


    ll tmp = N * (N-1) / 2;
    vector<ll> ans;
    ans.push_back(tmp);
    for(int i = M-1; i > 0; i--) {
        if( !tree.same(A[i], B[i]) ) {
            tmp -= tree.getSize(A[i]) *  tree.getSize(B[i]); 
        }
        tree.unionTree(A[i],B[i]);
        ans.push_back(tmp);
    }

    for(int i = M-1; i > -1; i--) {
        cout << ans[i] << endl;
    }



}


int main()
{
  solve();
	return 0;
}