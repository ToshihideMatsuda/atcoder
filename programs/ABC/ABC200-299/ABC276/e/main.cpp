#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) max(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) min(a,MIN(b,c))

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N 2*100000+5
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


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

ll dx[4] = { 1, -1, 0, 0};
ll dy[4] = { 0, 0, 1, -1};

vector<vector<char>> C;
vector<vector<ll>>  M; 
bool sameCheck(UnionFindTreeWithSize& tree, ll x,ll y, ll x2,ll y2) {
  if(M[x][y] == -1 || M[x2][y2] == -1) return false;
  return tree.same(M[x][y],M[x2][y2]);
}

void solve() {
  ll H, W; cin >> H >> W;
  UnionFindTreeWithSize tree((H+1)*(W+1));
  ll i = 0;

  rep(h,H+2){
    vector<char> c;
    vector<ll> m;
    rep(w,W+2) {
        c.push_back('#');
        m.push_back(-1);
    } 
    C.push_back(c);
    M.push_back(m);
  }

  rep(h,H)rep(w,W){
    cin >> C[h+1][w+1];
    M[h+1][w+1] = i; i++;
  }

  ll x,y;
  reps(h,1,H+1)reps(w,1,W+1) {
    if(C[h][w] == '.') {
      tree.insert(M[h][w]);
      rep(i,4) if(C[h+dx[i]][w+dy[i]] == '.') {
        //cout << "same:(" << h <<","<< w << "),(" << h+dx[i] <<","<< w+dy[i] << ")" << endl;
        tree.unionTree(M[h][w],M[h+dx[i]][w+dy[i]]);
      }
    } else if(C[h][w] == 'S') {
      x = h; y = w;
    }
  }

  if(sameCheck(tree,x+1,y,x-1,y) ||
     sameCheck(tree,x+1,y,x,y+1) ||
     sameCheck(tree,x+1,y,x,y-1) ||

     sameCheck(tree,x-1,y,x,y+1) ||
     sameCheck(tree,x-1,y,x,y-1) ||

     sameCheck(tree,x,y+1,x,y-1) ) {
     cout << "Yes" << endl;
  }
  else {
    cout << "No";
  }


  
}


int main()
{
  solve();
	return 0;
}