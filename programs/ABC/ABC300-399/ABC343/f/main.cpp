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


#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

//max: SegTree<ll> segTreeMax(N+1,    [](ll x, ll y) { return x < y ? y : x; }, -(1LL<<61));
//min: SegTree<ll> segTreeMin(N+1,    [](ll x, ll y) { return x < y ? x : y; }, (1LL<<61));
//sum: SegTree<ll> segTreeSum(N+1,    [](ll x, ll y) { return x + y; }, 0);
//sum: SegTree<ll> segTreeSumMod(N+1, [](ll x, ll y) { return (x + y) % MOD ; }, 0);
//xor: SegTree<ll> segTreeXor(N+1,    [](ll x, ll y) { return x ^ y; }, 0);
template<typename T>
struct SegTree {
    function<T(T,T)> compare; //比較用関数オブジェクト
    
    // 演算結果に影響しない0元
    // 最小値：inf, 最大値: -inf, sum:0, xor:0
    T ZERO;

    int n;          // 要素数
    vector<T> dat;  // セグメントtree配列
                    // dat.first 　　　　 :　[0,n)の値
                    // i番目の数列（葉）: dat[i + n - 1]
                    // dat[k]の子要素  : dat[ 2 * k + 1], dat[ 2 * k + 2]
                    // dat[k]の親要素  : dat[ (k - 1) / 2 ]
    
public:
    
    SegTree(int n_, function<T(T,T)> compare_, T Z) {
        int x = 1;
        while(x < n_) {
            x *= 2;         //n以上の 2^m形式に変換
        }
        n = x;
        compare = compare_;
        ZERO = Z;
        
        dat = vector<T> (n * 2 - 1, ZERO); //セグメント木は、要素数 sz * 2 - 1の配列を準備
    }
    
    
    // 区間[a,b)を値xで更新、遅延評価なし
    void update(int a, int b, T x) { //区間[a,b)を値xで更新
        for(int i = a; i < b; i++) {
            update(i,x);
        }
    }

    // dat[i]を値xで更新、遅延評価なし
    void update(int i, T x) { // i: 更新したい数列の位置（葉の位置）　x: 更新する値
        i += n - 1;                  // i番目の要素は i + n - 1の位置に格納
        dat[i] = x;
        while(i > 0) { //親をたどって値を更新していく
            i = (i - 1) / 2;
            dat[i] = compare(dat[i * 2 + 1], dat[i * 2 + 2] );
        }
    }  
    
    //区間[a,b)の値を取得するクエリ
    T query(int a, int b) { return query_sub(a, b, 0, 0, n); };
    
    //全区間の値を取得するクエリ
    T allquery() { return query_sub(0, n+1, 0, 0, n); };
    
    void debug() {

        vector<pair<ll,ll>> list;
        list.push_back({0,n});
        int i = 0;
        while(list.size()< dat.size()) {
            auto [l,r] = list[i++];
            list.push_back({l,l+(r-l+1)/2});
            list.push_back({l+(r-l+1)/2,r});
        }
        
        cout <<  "---dat---" << endl;
        for(int i = 0; i < dat.size(); i++) {
            auto [l,r] = list[i];
            string text = "[" + to_string(l) + ", " + to_string(r) + ") = ";
            cout << text;
            if(dat[i] == ZERO) {
                cout << "-" << endl;
            }
            else {
                cout << dat[i] << endl;
            }
        }
        
        cout <<  endl;
    }
    
private:
    T query_sub(int a, int b, int k, int l, int r) {
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
	
	ll N, Q; cin >> N >> Q;
	SegTree<  tuple<ll,ll,ll,ll>  > segTreeMax(N+1,  
	[](tuple<ll,ll,ll,ll>  X, tuple<ll,ll,ll,ll>  Y) { 
		
		auto[x0, cx0, x1, cx1] = X;
		auto[y0, cy0, y1, cy1] = Y;
		ll v0,cv0,v1,cv1;

		if(x0 == y0) {
			v0 = x0; cv0 = cx0 + cy0;
			if(x1 == y1) {
				v1 = x1; cv1 = cx1 + cy1;
			} else if(x1 < y1) {
				v1 = y1; cv1 = cy1;
			} else {
				v1 = x1; cv1 = cx1;
			}
		} else if(x0 < y0) {
			v0 = y0; cv0 = cy0;
			if(x0 == y1) {
				v1 = x0; cv1 = cx0 + cy1;
			} else if(x0 < y1) {
				v1 = y1; cv1 = cy1;
			} else {
				v1 = x0; cv1 = cx0;
			}
		}  else {
			v0 = x0; cv0 = cx0;
			if(x1 == y0) {
				v1 = x1; cv1 = cx1 + cy0;
			} else if(x1 < y0) {
				v1 = y0; cv1 = cy0;
			} else {
				v1 = x1; cv1 = cx1;
			}
		}

		tuple<ll,ll,ll,ll> t =  {v0,cv0,v1,cv1};
		return t;

	}, { -(1LL<<61),0LL, -(1LL<<61),0LL });
	
	rep(i,N) {
		ll a; cin >> a;
		segTreeMax.update(i+1,{a,1, -(1LL<<61),0LL } );
	} 

	rep(i,Q) {
		ll t; cin >> t;
		if(t == 1) {
			ll p, x; cin >> p >> x;
			segTreeMax.update(p,{x,1, -(1LL<<61),0LL } );
		} else {
			ll l, r; cin >> l >> r;
			auto [_0,_1,_2,ans] = segTreeMax.query(l,r+1);

			out(ans)
		}

	}

	return 0;
}