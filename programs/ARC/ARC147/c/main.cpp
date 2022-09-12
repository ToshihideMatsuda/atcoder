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

//#define MAX_N 2*100000+5
template<typename T>
struct SegTree {
    private :
#define MIN_MODE    0
#define MAX_MODE    1
#define SUM_MODE    2
#define XOR_MODE    3
    int mode =  MIN_MODE;  // 0:最小値, 1:最大値, 2:和, 3:XOR
    
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
    
    SegTree(int n_, int mode_, T Z) {
        int x = 1;
        while(x < n_) {
            x *= 2;         //n以上の 2^m形式に変換
        }
        n = x;
        ZERO = Z;
        
        vector<T>dattmp (n * 2 - 1, ZERO); //セグメント木は、要素数 sz * 2 - 1の配列を準備
        dat = dattmp;
        vector<T>lazytmp(n * 2 - 1, ZERO); //遅延評価配列も同じ数準備
        lazy = lazytmp;
        
    }
    
    
    // 区間[a,b)を値xで更新、最大最小-> 遅延評価。和, XOR, その他-> 通常
    void update(int a, int b, T x) {
        
        if(mode == MIN_MODE || mode == MAX_MODE)
        {
            updateLazy_forMinMax(a, b, x, 0, 0, n);
        }
        else if(mode == SUM_MODE || mode == XOR_MODE) {
            updateNolazy_forSum(a, b, x);
        }
        else {
            updateNolazy_forSum(a, b, x);
        }
    }
    // dat[a]を値xで更新
    void update(int a, T x) {
        update(a,a+1,x);
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
    void updateLazy_forMinMax(int a, int b, T x, int k, int l, int r) {
        eval(k);
        if(a <= l && r <= b ) {      // 区間にすっぽり収まる際にはlazyを更新
            lazy[k] = x ;
            eval(k);
        }  else if( a < r && l < b) { // 一部の区間が収まる場合
            updateLazy_forMinMax(a, b, x, 2 * k + 1, l          , (r + l)/ 2 );
            updateLazy_forMinMax(a, b, x, 2 * k + 2, (r + l) / 2, r );
            dat[k] = choice(dat[k * 2 + 1], dat[k * 2 + 2] );
            
        }
    }
    
    //その時点で値を更新する
    void updateNolazy_forSum(int i, T x) { // i: 更新したい数列の位置（葉の位置）　x: 更新する値
        i += n - 1;                  // i番目の要素は i + n - 1の位置に格納
        dat[i] = x;
        while(i > 0) { //親をたどって値を更新していく
            i = (i - 1) / 2;
            dat[i] = choice(dat[i * 2 + 1], dat[i * 2 + 2] );
        }
    }
    
    //その時点で値を更新する
    void updateNolazy_forSum(int a, int b, T x) { //区間[a,b)を値xで更新
        for(int i = a; i < b; i++) {
            updateNolazy_forSum(i,x);
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
        
        return choice(lv,rv);
    }
    
    T choice(T a, T b) {
        return
            mode == MIN_MODE ? min(a, b) :
            mode == MAX_MODE ? max(a, b) :
            mode == SUM_MODE ? a + b     :
            mode == XOR_MODE ? a ^ b     : ZERO;
    }
    

};

ll MAX_N = 100000005;
void solve() {
  ll N; cin >> N;
  bool ck[N+5]; rep(i,N+5) ck[i] = false;
  SegTree<ll> X(MAX_N, SUM_MODE, 0);
  vector<tuple<ll,ll,ll>> LRI;
  vector<tuple<ll,ll,ll>> RLI;

  rep(i,N){
    ll l, r; cin >> l >> r;
    LRI.push_back({l,r,i});
    RLI.push_back({r,l,i});
  }
  sort(LRI.begin(),LRI.end());
  sort(RLI.begin(),RLI.end(),greater<tuple<ll,ll,ll>>());

  ll ii = 0;
  bool turn = true;
  while(X.allquery < N) {
    ll l, r, i;
    if(turn) {
      //左から貪欲
      tie(l,r,i) = LRI[ii];
      if(ck[i]){
         turn = !turn;
         continue;
      }
      ck[i] = true;

      if(X.query(l,r+1) > 1 ) {
        X.update(l,X.query(l,r+1)+1);
      } else {
        X.update(r,1);
      }

    } else {
      //右から貪欲
      tie(r,l,i) = RLI[ii];
      if(ck[i]) {
        turn = !turn;
        ii++;
        continue;
      };
      ck[i] = true;

      X.update(l,1);

      ii ++;
    }

    turn = !turn;
  }

  sort(X.begin(),X.end());



  vector<ll> S2(N);
  S2[0] = 0;
  reps(i,1,N){
    S2[i] = S2[i-1] + (X[i] - X[0]);
  }
  ll ans = 0;
  reps(i,1,N){
    ans += (N-i) * (X[N-i] - X[0]) - S2[N-1-i];
  }

  cout << ans << endl;



}


int main()
{
  solve();
	return 0;
}