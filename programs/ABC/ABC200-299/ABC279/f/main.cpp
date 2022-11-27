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

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


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

void solve() {
  ll N, Q; cin >> N >> Q;
  UnionFindTree<ll> uft;

  ll rootOf[N+1];
  unordered_map<ll,ll> rootBox;

  reps(i,1,N+1) {
    uft.insert(i);
    rootOf[i] = i;
    rootBox[i] = i;
  }
  ll cnt = N;

  rep(_,Q) {
    ll t; cin >> t;
    if(t == 1) {
      ll x,y; cin >> x >> y;
      if(rootBox.count(rootOf[x]) && rootBox.count(rootOf[y])) {
        uft.unionTree(rootOf[x],rootOf[y]);
        rootBox.erase(rootOf[y]);
      } else if(rootBox.count(rootOf[y])){
        rootBox[rootOf[y]] = x;
        rootOf[x] = rootOf[y];
      }
      rootOf[y] = -1;
    } else if(t == 2) {
      ll x; cin >> x;
      cnt++;
      uft.insert(cnt);
      if(rootOf[x] == -1){
        rootOf[x] = cnt;
        rootBox[cnt] = x;
      } else {
        uft.unionTree(rootOf[x],cnt);
      }
    } else {
      ll x; cin >> x;
      cout << rootBox[uft.root(x)] << endl; 
    }

  }
}


int main()
{
  solve();
	return 0;
}