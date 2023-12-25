#include <bits/stdc++.h> 
#include <atcoder/all>

using namespace atcoder;
using namespace std;

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



// powB[k][n] = B[k]^n (0<= n <= N)となる配列
ll powB[100][1000000+5];

//ローリングハッシュ用のライブラリ
struct RollingHash {
  
  private:
  //法M
  const ll M = 998244353;

  //基数
  vector<ll> B;

  //　基数のサイズ
  ll K;// = 0;

  // ローリングハッシュ値(※)を格納する配列
  // ※ hash[k] = S[0]*B[k]^(N-1) + S[1]*B[k]^(N-2) + ... + S[N-1] 
  vector<ll> hash;

  //文字列の長さ
  ll N;

public:
  RollingHash(string const& S) {
    
    N = S.size();
    if(B.size() == 0) {
      B = { 7013813588750972951LL, 8929143633738088283LL, 4837909145654321621LL, 6819033938186690237LL, 5107328697654825071LL};
//        6984644639313321301LL, 7981742035558655513LL, 5012529736381582537LL, 7764346403316436763LL, 8785404510772599077LL };

      K = B.size();
      rep(i,K) B[i] %= M;

      // powB[k][n] = B[k]^n (0<= n <=N)の計算
      rep(k,K) {
        powB[k][0] = 1;
        rep(n,N) powB[k][n+1] = (powB[k][n] * B[k]) % M ;
      }
    }

    //ハッシュ値の初期登録
    hash.resize(K);
    rep(k,K) {
      hash[k] = 0;
      rep(n,N) hash[k] = (hash[k] * B[k] + S[n]) % M;
    }
  }

  bool isSame(RollingHash other) {
    if(other.hash.size() == hash.size()) {
      rep(k,K) {
        if(other.hash[k] != hash[k]) return false;
      }
      return true;
    }
    return false;
  }

  // i番目(0-indexed)の文字bfがafに置き換わる場合のハッシュ値の計算
  //(af,bfは入力元が管理)
  void swap(ll i, char bf, char af) {
    rep(k,K) {
      hash[k] = (hash[k] + (af * powB[k][N-1-i]) - (bf * powB[k][N-1-i] )+ M * 100000000) % M;
    }
  }

  //末尾にafが加わり、先頭bfが除去された場合のハッシュ値の計算
  //(af,bfは入力元が管理)
  void push(char bf, char af) {
    rep(k,K) {
      hash[k] = (hash[k] * B[k] + af - bf * powB[k][N] + M * 100000000) % M;
    }
  }

};


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
	ll N, Q; cin >> N >> Q;
	string S; cin >> S;


//max: SegTreeAbstract<ll> segTreeMax(N+1, [](ll x, ll y) { return x < y ? y : x; }, -(1LL<<61));
//min: SegTreeAbstract<ll> segTreeMin(N+1, [](ll x, ll y) { return x < y ? x : y; }, (1LL<<61));
//sum: SegTreeAbstract<ll> segTreeSum(N+1, [](ll x, ll y) { return x + y; }, 0);
//xor: SegTreeAbstract<ll> segTreeXor(N+1, [](ll x, ll y) { return x ^ y; }, 0);


	 SegTreeAbstract<RollingHash> segTreeMax(N+1, [](ll x, ll y) { return x < y ? y : x; }, -(1LL<<61));


	return 0;
}