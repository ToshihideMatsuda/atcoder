#include <bits/stdc++.h> 
#include <atcoder/all>

using namespace atcoder;
using namespace std;
// 多倍長テンプレ（デバッグだとダメかも）
/* ---------------------- ここから ---------------------- */
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
// 任意長整数型
using bll = mp::cpp_int;
// 仮数部が10進数で1024桁の浮動小数点数型(TLEしたら小さくする)
using real = mp::number<mp::cpp_dec_float<1024>>;
/* ---------------------- ここまで ---------------------- */

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
#define MINF_LL (-9223372036854775808LL)
#define MOD 998244353

#define MAX_N (2*100000+5)
vector<pair<ll, ll>> G[MAX_N]; // G[from] = { cost, to } 頂点 from->to の辺のコストがcost
bool used[MAX_N];
ll usedCnt =0;
ll N, M;
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


//クラスカル法 入力N: 1...Nを頂点とするグラフGが対象
ll kruskal(int N) {
    vector<tuple<ll, int, int>> edges; // (cost,from,to)
    for (int i = 1; i <= N; i++) {
        for (auto &e : G[i]) {
            int to = e.second;
            ll cost = e.first;
            if (i < to) { // 重複を避けるために一方向のみをリストに追加
                edges.emplace_back(cost, i, to);
            }
        }
    }

    UnionFindTree<ll> uft;
	reps(i,1,N+1) {
		uft.insert(i);
	}
    
    sort(edges.begin(), edges.end()); // コストでソート
    ll total_cost = 0;

    //コスト順に辺を追加していく。unionfind木ですでに連結済みの辺はスキップ
    for (auto &e : edges) {
        auto [cost, u, v] = e;
        if (!uft.same(u, v)) {
            uft.unionTree(u, v);
            total_cost += cost;
        }
    }

    reps(i,1,N+1) if(uft.same(1,i) == false) return -1;

    return total_cost;




}


int main()
{
	cin >> N >> M; 

	map<ll,map<ll,ll>> mp;

	vector<pair<ll,vector<ll>>> CA;

	rep(i,M) {
		ll k, c; cin >> k >> c;
		vector<ll> a(k); 
		cin >> a[0];
		reps(j,1,k) {
			cin >> a[j];
			G[a[0]].push_back({c,a[j]});
			G[a[j]].push_back({c,a[0]});
		}

	}

	out(kruskal(N))


	return 0;
}