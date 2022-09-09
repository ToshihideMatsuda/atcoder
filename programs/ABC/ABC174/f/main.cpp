#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) max(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) min(a,MIN(b,c))

#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5
struct SegTree {
    private :
    
    // 演算結果に影響しない0元
    // 最小値：inf, 最大値: -inf, sum:0, xor:0
    multiset<ll> ZERO;
    
    
    int n;          // 要素数
    vector<multiset<ll>> dat;  // セグメントtree配列
                    // dat[0] 　　　　　　: [0,n)の値
                    // i番目の数列（葉）   : dat[i + n - 1]
                    // dat[k]の子要素    : dat[ 2 * k + 1], dat[ 2 * k + 2]
                    //                    dat
                    // dat[k]の親要素    : dat[ (k - 1) / 2 ]

    vector<multiset<ll>> lazy; // 遅延評価配列
    
public:
    
    SegTree(int n_, int mode_, multiset<ll> Z) {
        int x = 1;
        while(x < n_) {
            x *= 2;         //n以上の 2^m形式に変換
        }
        n = x;
        ZERO = Z;
        
        vector<multiset<ll>>dattmp (n * 2 - 1, ZERO); //セグメント木は、要素数 sz * 2 - 1の配列を準備
        dat = dattmp;
        vector<multiset<ll>>lazytmp(n * 2 - 1, ZERO); //遅延評価配列も同じ数準備
        lazy = lazytmp;
        
    }
    
    
    // 区間[a,b)を値xで更新、最大最小-> 遅延評価。和, XOR, その他-> 通常
    void update(int a, int b, multiset<ll> x) {
        updateNolazy_forSum(a, b, x);
    }
    // dat[a]を値xで更新
    void update(int a, multiset<ll> x) {
        update(a,a+1,x);
    }
    
    //区間[a,b)の値を取得するクエリ
    multiset<ll> query(int a, int b) { return query_sub(a, b, 0, 0, n); };
    
    //全区間の値を取得するクエリ
    multiset<ll> allquery() { return query_sub(0, n+1, 0, 0, n); };
    
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
    
    //その時点で値を更新する
    void updateNolazy_forSum(int i, multiset<ll> x) { // i: 更新したい数列の位置（葉の位置）　x: 更新する値
        i += n - 1;                  // i番目の要素は i + n - 1の位置に格納
        dat[i] = x;
        while(i > 0) { //親をたどって値を更新していく
            i = (i - 1) / 2;
            dat[i] = choice(dat[i * 2 + 1], dat[i * 2 + 2] );
        }
    }
    
    //その時点で値を更新する
    void updateNolazy_forSum(int a, int b, multiset<ll> x) { //区間[a,b)を値xで更新
        for(int i = a; i < b; i++) {
            updateNolazy_forSum(i,x);
        }
    }
    
private:
    multiset<ll> query_sub(int a, int b, int k, int l, int r) {
        eval(k);
        if(b <= l || r <= a)
            return ZERO;    //区間外
        if(a <= l && r <= b )
            return dat[k]; // 区間にすっぽり収まる
        
        //一部重なる
        multiset<ll> lv = query_sub(a, b, 2 * k + 1, l          , (r + l)/ 2 );
        multiset<ll> rv = query_sub(a, b, 2 * k + 2, (r + l) / 2, r );
        
        return choice(lv,rv);
    }
    
    multiset<ll> choice(multiset<ll> a, multiset<ll> b) {
      multiset<ll> ret;
      set_union(
        a.begin(),a.end(),
        b.begin(),b.end(),
        inserter(ret, ret.end())
      );
      return ret;
    }
    

};



void solve() {
  ll N, Q; cin >> N >>Q;

  multiset<ll> z;
  SegTree tree(N,0,z);
  rep(i,N) {
    ll c;
    cin >> c;

    multiset<ll> s;
    s.insert(c);
    
    tree.update(i,s);
  }

  rep(i,Q) {
    ll l, r; cin >> l >> r;
    multiset<ll> s = tree.query(l-1,r);
    cout << s.size() << endl;
  }

}


int main()
{
  solve();
	return 0;
}