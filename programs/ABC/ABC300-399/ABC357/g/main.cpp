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
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

#include <iostream>
#include <vector>

using namespace std;

class LazySegmentTree {
public:
    LazySegmentTree(const vector<int>& data) {
        n = data.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 1); // 遅延配列は1で初期化（掛け算の単位元）
        build(data, 0, 0, n - 1);
    }

    void update_range(int l, int r, int val) {
        update_range(0, 0, n - 1, l, r, val);
    }

    int query_range(int l, int r) {
        return query_range(0, 0, n - 1, l, r);
    }

private:
    int n;
    vector<int> tree, lazy;

    void build(const vector<int>& data, int node, int start, int end) {
        if (start == end) {
            tree[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            build(data, 2 * node + 1, start, mid);
            build(data, 2 * node + 2, mid + 1, end);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
        }
    }

    void propagate(int node, int start, int end) {
        if (lazy[node] != 1) { // 遅延があれば適用
            tree[node] *= lazy[node];
            if (start != end) {
                lazy[2 * node + 1] *= lazy[node];
                lazy[2 * node + 2] *= lazy[node];
            }
            lazy[node] = 1;
        }
    }

    void update_range(int node, int start, int end, int l, int r, int val) {
        propagate(node, start, end);
        if (start > end || start > r || end < l) {
            return;
        }

        if (start >= l && end <= r) {
            tree[node] *= val;
            if (start != end) {
                lazy[2 * node + 1] *= val;
                lazy[2 * node + 2] *= val;
            }
            return;
        }

        int mid = (start + end) / 2;
        update_range(2 * node + 1, start, mid, l, r, val);
        update_range(2 * node + 2, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node + 1] + tree[2 * node + 2];
    }

    int query_range(int node, int start, int end, int l, int r) {
        propagate(node, start, end);
        if (start > end || start > r || end < l) {
            return 0;
        }

        if (start >= l && end <= r) {
            return tree[node];
        }

        int mid = (start + end) / 2;
        int left_sum = query_range(2 * node + 1, start, mid, l, r);
        int right_sum = query_range(2 * node + 2, mid + 1, end, l, r);
        return left_sum + right_sum;
    }
};

// 使用例
int main() {
    vector<int> data = {1, 2, 3, 4, 5};
    LazySegmentTree seg_tree(data);

    seg_tree.update_range(1, 3, 2);  // [1, 4, 6, 8, 5] に更新
    cout << seg_tree.query_range(0, 4) << endl;  // 全体の合計: 24
    cout << seg_tree.query_range(1, 3) << endl;  // 部分区間の合計: 18

    return 0;
}
