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


using mint = modint998244353;

//max: SegTree<ll> segTreeSum(N+1,    [](ll x, ll y) { return x + y }, 0 );
template<typename T>
struct SegTree {

    // 演算結果に影響しない0元
    // 最小値：-inf, 最大値: inf
    T ZERO;

    private :
    function<T(T,T)> compare; //比較用関数オブジェクト
    
    
    int n;          // 要素数
    vector<T> dat;  // セグメントtree配列
                    // dat[0] 　　　　　　: [0,n)の値
                    // i番目の数列（葉）   : dat[i + n - 1]
                    // dat[k]の子要素    : dat[ 2 * k + 1], dat[ 2 * k + 2]
                    // dat[k]の親要素    : dat[ (k - 1) / 2 ]

    vector<T> lazy; // 遅延評価配列
    
    vector<pair<ll,ll>> area; // 範囲定義 area[k] = [a,b);

public:
    
    SegTree(int n_, function<T(T,T)> compare_, T Z) {
        int x = 1;
        while(x < n_) {
            x *= 2;         //n以上の 2^m形式に変換
        }
        n = x;
        ZERO = Z;
        compare = compare_;

        dat = vector<T>(n * 2 - 1, ZERO); //セグメント木は、要素数 sz * 2 - 1の配列を準備
        lazy = vector<T>(n * 2 - 1, ZERO); //遅延評価配列も同じ数準備;

        area.push_back({0,n});
        int i = 0;
        while(area.size()< dat.size()) {
            auto [l,r] = area[i++];
            area.push_back({l,l+(r-l+1)/2});
            area.push_back({l+(r-l+1)/2,r});
        }

    }
    
    // dat[a]を値xで更新
    void update(int a, T x) {
        update(a,a+1,x);
    }

    // 区間[a,b)を値xで更新、最大最小-> 遅延評価。和, XOR, その他-> 通常
    void update(int a, int b, T x) {
        updateLazy(a, b, x, 0, 0, n);
    }
    
    //区間[a,b)の値を取得するクエリ
    T query(int a, int b) { 
        return query_sub(a, b, 0, 0, n); };
    
    //全区間の値を取得するクエリ
    T allquery() { return query_sub(0, n+1, 0, 0, n); };
    
    void debug() {

        cout <<  "---dat---" << endl;
        for(int i = 0; i < dat.size(); i++) {
            auto [l,r] = area[i];
            string text = "[" + to_string(l) + ", " + to_string(r) + ") = ";
            cout << text;
            if(dat[i] == ZERO) {
                cout << "-" << endl;
            }
            else {
                cout << dat[i] << endl;
            }
        }

        cout <<  "---lazy---" << endl;
        for(int i = 0; i < lazy.size(); i++) {
            auto [l,r] = area[i];
            string text = "[" + to_string(l) + ", " + to_string(r) + ") = ";
            cout << text;
            if(lazy[i] == ZERO) {
                cout << "-" << endl;
            }
            else {
                cout << lazy[i] << endl;
            }
        }
        cout <<  endl;
    }
    
    //lazy[k]に登録してあった値を、１階層下の子要素に伝播させて、自身の値も変更
    void eval(int k) {
        if(lazy[k] == ZERO) return ;

        if(k < n -1) //kは末端ノード（葉）ではない
        {

            auto [l, r] = area[k];
            ll x = lazy[k] / (r - l);

            auto [l1, r1] = area[2 * k + 1];
            auto [l2, r2] = area[2 * k + 2];

            //自分の子要素に伝搬　(子要素は必要であれば次世代に伝搬) 
            if(lazy[2 * k + 1] == ZERO) {
                lazy[2 * k + 1] = x * (r1 - l1);
            } else {
                lazy[2 * k + 1] += x * (r1 - l1);
            }


            if(lazy[2 * k + 2] == ZERO) {
                lazy[2 * k + 2] = x * (r2 - l2);
            } else {
                lazy[2 * k + 2] += x * (r2 - l2);
            }

        }
        if(dat[k] == ZERO) {
            dat[k] = lazy[k];
        } else {
            dat[k] += lazy[k];
        }

        lazy[k] = ZERO;
    }
    
private:
    void updateLazy(int a, int b, T x, int k, int l, int r) {
        eval(k);
        if(a <= l && r <= b ) {      // 区間にすっぽり収まる際にはlazyを更新
            if(lazy[k] == ZERO) {
                lazy[k] = x * (r-l);
            } else {
                lazy[k] += x * (r-l);
            }
            eval(k);
        }  else if( a < r && l < b) { // 一部の区間が収まる場合
            updateLazy(a, b, x, 2 * k + 1, l          , (r + l)/ 2 );
            updateLazy(a, b, x, 2 * k + 2, (r + l) / 2, r );
            dat[k] = compare(dat[k * 2 + 1], dat[k * 2 + 2] );
        } else {
            int i = 0;
        }
    }
    
private:
    T query_sub(int a, int b, int k, int l, int r) {
        eval(k);
        if(b <= l || r <= a)
            return ZERO;    //区間外
        if(a <= l && r <= b )
            return dat[k]; // 区間にすっぽり収まる
        
        //一部重なる
        T lv = query_sub(a, b, 2 * k + 1, l          , (r + l)/ 2 );
        T rv = query_sub(a, b, 2 * k + 2, (r + l) / 2, r );
        
        return compare(lv,rv);
    }

};



// vector<ll> data = {1,2,3,4,5};
// SegTreeProductSum<ll> seg(data, [](ll x, ll y) { return x + y;  }, 0, 1);

template<typename T>
struct SegTreeProductSum {

    // 演算結果に影響しない0元
    // 最小値：-inf, 最大値: inf
    T ONE;
    T ZERO;

    private :
    function<T(T,T)> compare; //比較用関数オブジェクト
    
    
    int n;          // 要素数
    vector<T> dat;  // セグメントtree配列
                    // dat[0] 　　　　　　: [0,n)の値
                    // i番目の数列（葉）   : dat[i + n - 1]
                    // dat[k]の子要素    : dat[ 2 * k + 1], dat[ 2 * k + 2]
                    // dat[k]の親要素    : dat[ (k - 1) / 2 ]

    vector<T> lazy; // 遅延評価配列
    
    vector<pair<ll,ll>> area; // 範囲定義 area[k] = [a,b);

public:
    
    SegTreeProductSum(const vector<T>& data, function<T(T,T)> compare_, T Z, T O) {
        int x = 1;
        int n_ = data.size();
        while(x < n_) {
            x *= 2;         //n以上の 2^m形式に変換
        }
        n = x;
        ONE = O;
        ZERO = Z;
        compare = compare_;

        dat = vector<T>(n * 2 - 1, ZERO); //セグメント木は、要素数 sz * 2 - 1の配列を準備
        lazy = vector<T>(n * 2 - 1, ONE); //遅延評価配列も同じ数準備;

        area.push_back({0,n});
        int i = 0;
        while(area.size()< dat.size()) {
            auto [l,r] = area[i++];
            area.push_back({l,l+(r-l+1)/2});
            area.push_back({l+(r-l+1)/2,r});
        }

        build(data, 0, 0, n - 1);
    }
    
    /** dat[a]に値xをかける */
    void update(int a, T x) {
        update(a,a+1,x);
    }

    /** 区間[a,b)に値xをかける　*/
    void update(int a, int b, T x) {
        updateLazy(a, b, x, 0, 0, n);
    }
    
    /** 区間[a,b)の値を取得するクエリ */
    T query(int a, int b) { 
        return query_sub(a, b, 0, 0, n); };
    
    //全区間の値を取得するクエリ
    T allquery() { return query_sub(0, n+1, 0, 0, n); };
    
    void debug() {

        cout <<  "---dat---" << endl;
        for(int i = 0; i < dat.size(); i++) {
            auto [l,r] = area[i];
            string text = "[" + to_string(l) + ", " + to_string(r) + ") = ";
            cout << text;
            if(dat[i] == ONE) {
                cout << "-" << endl;
            }
            else {
                cout << dat[i] << endl;
            }
        }

        cout <<  "---lazy---" << endl;
        for(int i = 0; i < lazy.size(); i++) {
            auto [l,r] = area[i];
            string text = "[" + to_string(l) + ", " + to_string(r) + ") = ";
            cout << text;
            if(lazy[i] == ONE) {
                cout << "-" << endl;
            }
            else {
                cout << lazy[i] << endl;
            }
        }
        cout <<  endl;
    }
    
    //lazy[k]に登録してあった値を、１階層下の子要素に伝播させて、自身の値も変更
    void eval(int k) {
        if(lazy[k] == ONE) return ;

        if(k < n -1) //kは末端ノード（葉）ではない
        {

            auto [l, r] = area[k];
            ll x = lazy[k] / (r - l);

            auto [l1, r1] = area[2 * k + 1];
            auto [l2, r2] = area[2 * k + 2];

            //自分の子要素に伝搬　(子要素は必要であれば次世代に伝搬) 
            lazy[2 * k + 1] *= x * (r1 - l1);
            lazy[2 * k + 2] *= x * (r2 - l2);
            

        }
		if(dat[k] == ZERO){
			dat[k] = lazy[k];
		} else {
        	dat[k] *= lazy[k];
		}

        lazy[k] = ONE;
    }
    
private:
    void build(const vector<T>& data, int node, int start, int end) {
        if (start == end) {
            dat[node] = data[start];
        } else {
            int mid = (start + end) / 2;
            build(data, 2 * node + 1, start, mid);
            build(data, 2 * node + 2, mid + 1, end);
            dat[node] = compare(dat[2 * node + 1], dat[2 * node + 2]);
        }
    }

    void updateLazy(int a, int b, T x, int k, int l, int r) {
        eval(k);
        if(a <= l && r <= b ) {      // 区間にすっぽり収まる際にはlazyを更新
            lazy[k] *= x * (r-l);
            eval(k);
        }  else if( a < r && l < b) { // 一部の区間が収まる場合
            updateLazy(a, b, x, 2 * k + 1, l          , (r + l)/ 2 );
            updateLazy(a, b, x, 2 * k + 2, (r + l) / 2, r );
            dat[k] = compare(dat[k * 2 + 1], dat[k * 2 + 2] );
        } else {
            int i = 0;
        }
    }
    
private:
    T query_sub(int a, int b, int k, int l, int r) {
        eval(k);
        if(b <= l || r <= a)
            return ZERO;    //区間外
        if(a <= l && r <= b )
            return dat[k]; // 区間にすっぽり収まる
        
        //一部重なる
        T lv = query_sub(a, b, 2 * k + 1, l          , (r + l)/ 2 );
        T rv = query_sub(a, b, 2 * k + 2, (r + l) / 2, r );
        
        return compare(lv,rv);
    }

};




int main()
{
	SegTreeProductSum<mint> XY;

	ll N, Q; cin >> N >> Q;

	SegTree<mint> 			AB(N+1, [](mint x, mint y) { return x + y;  }, 0);

	vector<mint> A(N), B(N);
	rep(i,N) cin >> A[i];
	rep(i,N) cin >> B[i];

	rep(i,N) AB.update(i,A[i]*B[i]);

	vector<mint> empty(N+1,0);

	SegTreeProductSum<mint> A(empty,  [](mint x, mint y) { return x + y;  }, 0, 1);
	SegTreeProductSum<mint> B(empty,  [](mint x, mint y) { return x + y;  }, 0, 1);
	SegTreeProductSum<mint> XY(empty, [](mint x, mint y) { return x + y;  }, 0, 1);

	while(Q--) {
		ll t, l, r; cin >> t >> l >> r;
		if(t == 1) {
			ll x ; cin >> x;
			X.update(l,r+1,);
		} else if (t == 2) {
			ll x ; cin >> x;

		} else {

		}

	} 
	


	return 0;
}