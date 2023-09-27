#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
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
#define out(s) cout << s << endl;
#define out2(s) cout << s;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 1000000007

#define MAX_N (2*100000+5)


struct UnionFindTreeWithSize {

    unordered_map <int,int> tree;  // T -> TのUnionTreeの実態
    unordered_map <int,int>dep; // unionfind木の深さ

    unordered_map<int,unordered_map<int,int>>rootClass;

    UnionFindTreeWithSize() {}

    void insert(int edge,int c){
        tree[edge] = -1;
        dep[edge] = 1;
        rootClass[edge][c]=1;
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

        if(getSize(x) >= getSize(y) ) {
            tree[x] += tree[y]; //負数の要素をくっつける
            tree[y] = x;
            dep[y] ++;
            classjoin(x,y);
        } else {
            tree[y] += tree[x]; //負数の要素をくっつける
            tree[x] = y;
            dep[x] ++;
            classjoin(y,x);
        }
    }

    void classjoin(int x, int y){
    	for(auto idx=rootClass[y].begin();idx!=rootClass[y].end();++idx){
    		ll c,cnt;
    		tie(c,cnt)=*idx;
    		rootClass[x][c]+=cnt;
    	}
    	rootClass[y].clear();
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

    int get(ll x,ll y){
    	ll r=root(x);
    	return rootClass[r][y];
    }

};


int main()
{
	ll n,q;cin>>n>>q;
	UnionFindTreeWithSize uft;
	reps(i,1,1+n){
		ll c;
		cin>>c;
		uft.insert(i,c);
	}
	while(q--){
		ll t;cin>>t;
		if(t==1){
			ll a,b;cin>>a>>b;
			uft.unionTree(a,b);
		}else{
			ll x,y;cin>>x>>y;
			cout<<uft.get(x,y)<<endl;
		}
		}
}