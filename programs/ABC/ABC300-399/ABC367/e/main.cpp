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


#define INF (2147483647)
#define MINF (-2147483648)
#define INF_LL  (9223372036854775807LL)
#define MINF_LL (-9223372036854775807LL)
#define MOD 998244353

#define MAX_N (2*100000+5)

ll p = 707972951LL;
ll s = 418311299LL;
ll N, K; 


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



int main()
{
    cin >> N >> K;
    //out direction
    vector<ll> X(N);rep(i,N) { cin >> X[i]; X[i]--; }
    //in direction
    vector<vector<ll>> Y(N);rep(i,N) Y[X[i]].push_back(i);

    vector<ll> A(N);rep(i,N) cin >> A[i];
    if(K == 0) {
        OUT(A," ")
        return 0;
    }
    vector<ll> ans(N,-1);

    UnionFindTree<ll> utr;
    rep(i,N) utr.insert(i);
    rep(i,N) utr.unionTree(i,X[i]);

    set<ll> R;
    rep(i,N) if( R.count(utr.root(i)) == false ) {
        R.insert(utr.root(i));
        set<ll> s;
        ll j = i;
        while(s.count(j) == false) {
            s.insert(j);
            j = X[j];
        }
        vector<pair<ll,ll>> h;
        vector<ll> w = {j};

        while(X[w.back()] != w[0]) {
            w.push_back(X[w.back()]);
        }

        ll loop = w.size();
        rep(i,loop) if(1 < Y[w[i]].size()) h.emplace_back(w[i],i);

        rep(i,loop) ans[w[i]] = A[w[(K+i) % loop]];

        function<void(ll, vector<ll>&, ll)>  f = [&](ll p, vector<ll>& branch, ll i) {
            if(K <= branch.size()) {
                ans[p] = A[branch[branch.size() - K]];
            } else {
                ans[p] = A[w[ (K - branch.size() + i) % loop]];
            }

            for(auto y:Y[p]) if(ans[y] == -1){
                branch.push_back(p);
                f(y, branch, i);
                branch.pop_back();
            }
        };

        for(auto p : h) {
            vector<ll> a = {};
            f(p.first,a,p.second);
        }
    }

    OUT(ans, " ")




	return 0;
}