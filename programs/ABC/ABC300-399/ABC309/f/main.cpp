#include <bits/stdc++.h> 
#include <atcoder/all>
using namespace atcoder;
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
#define out0(s) cout << s;
#define out(s) out1(s)
#define out1(s) cout << s << endl;
#define out2(s,t) cout << s << t << endl;
#define out3(s,t,r) cout << s << t << r << endl;
#define out4(s,t,r,u) cout << s << t << r << u << endl;
#define out5(s,t,r,u,o) cout << s << t << r << u << o << endl;
#define outd(s) cout << setprecision(15) << s << endl;
#define pb(s) push_back(s)

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N (2*100000+5)


//max: SegTreeAbstract<ll> segTreeMax(N+1, [](ll x, ll y) { return x < y ? y : x; }, -(1LL<<61));
//min: SegTreeAbstract<ll> segTreeMin(N+1, [](ll x, ll y) { return x < y ? x : y; }, (1LL<<61));
//sum: SegTreeAbstract<ll> segTreeSum(N+1, [](ll x, ll y) { return x + y; }, 0);
//xor: SegTreeAbstract<ll> segTreeXor(N+1, [](ll x, ll y) { return x ^ y; }, 0);
template<typename T>
struct SegTreeAbstract {
    //最大値: compare = [](ll x, lly)
    function<T(T,T)> compare; //比較用関数オブジェクト
    
    
    // 演算結果に影響しない0元
    // 最小値：inf, 最大値: -inf, sum:0, xor:0
    T ZERO;
    
    
    int n;          // 要素数
    vector<T> dat;  // セグメントtree配列
                    // dat[0] 　　　　　　: [0,n)の値
                    // i番目の数列（葉）   : dat[i + n - 1]
                    // dat[k]の子要素    : dat[ 2 * k + 1], dat[ 2 * k + 2]
                    //                    dat
                    // dat[k]の親要素    : dat[ (k - 1) / 2 ]

    vector<T> lazy; // 遅延評価配列
    
public:
    
    SegTreeAbstract(int n_, function<T(T,T)> compare_, T Z) {
        int x = 1;
        while(x < n_) {
            x *= 2;         //n以上の 2^m形式に変換
        }
        n = x;
        compare = compare_;
        ZERO = Z;
        
        vector<T>dattmp (n * 2 - 1, ZERO); //セグメント木は、要素数 sz * 2 - 1の配列を準備
        dat = dattmp;
        vector<T>lazytmp(n * 2 - 1, ZERO); //遅延評価配列も同じ数準備
        lazy = lazytmp;
        
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
        cout <<  "---dat---" << endl;
        for(int i = 0; i < dat.size(); i++) {
            if(dat[i] == ZERO) {
                cout << "- ";
            }
            else {
                cout << dat[i] << " ";
            }
        }
        
        cout <<  endl;
        
        cout <<  "---lazy---" << endl;
        for(int i = 0; i < lazy.size(); i++) {
            if(lazy[i] == ZERO) {
                cout << "- ";
            }
            else {
                cout << lazy[i] << " ";
            }
        }
        cout <<  endl;
    }
    
    //lazy[k]に登録してあった値を、１階層下の子要素に伝播させて、自身の値も変更
    void eval(int k) {
        if(lazy[k] == ZERO) return ;
        if(k < n -1) //kは末端ノード（葉）ではない
        {
            lazy[2 * k + 1] = lazy[k];
            lazy[2 * k + 2] = lazy[k];
        }
        dat[k] = lazy[k];
        lazy[k] = ZERO;
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
	ll N; cin >> N;
	vector<ll> B_[3];
	map<ll,ll> press[3];
	vector<tuple<ll,ll,ll>> B;
	vector<tuple<ll,ll,ll>> Bpressed(N);
	rep(i,N) {
		vector<ll> BB(3);
		rep(j,3) cin >>BB[j];
		sort(BB.begin(),BB.end());
		rep(j,3) B_[j].push_back(BB[j]);
		B.push_back({BB[0], -BB[1], BB[2] });
	}
	
	sort(B.begin(),B.end());

	rep(j,3) sort(B_[j].begin(),B_[j].end());
	rep(j,3) {
		ll i = 1;
		rep(k,N)if(press[j].count(B_[j][k])) {
			i++;
		} else {
			press[j][B_[j][k]] = i;
			i++;
		}
	} 

	rep(i,N) {
		rep(j,3){
			auto [h,w,d] = B[i];
			Bpressed[i] = { press[0][h],  press[1][-w], press[2][d] };
		}
	}

	SegTreeAbstract<ll> segTreeMin(N+1, [](ll x, ll y) { return x < y ? x : y; }, (1LL<<61));

	rep(i,N) {
		auto [h,w,d] = Bpressed[i];
		ll v = segTreeMin.query(0,w);
		if(v < d) {
			out("Yes")
			return 0;
		} else {
			ll cur =  segTreeMin.query(w,w+1);
			segTreeMin.update(w,MIN(cur,d));
		}
	}


	out("No")
	return 0;
}