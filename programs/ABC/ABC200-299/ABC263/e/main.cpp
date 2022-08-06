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

#define MAX_N 2*100000

template <std::uint_fast64_t Modulus> class modint {
  using u64 = std::uint_fast64_t;

public:
  u64 a;

  constexpr modint(const u64 x = 0) noexcept : a(x % Modulus) {}
  constexpr u64 &value() noexcept { return a; }
  constexpr const u64 &value() const noexcept { return a; }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if (a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if (a < rhs.a) {
      a += Modulus;
    }
    a -= rhs.a;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  constexpr modint &operator/=(modint rhs) noexcept {
    u64 exp = Modulus - 2;
    while (exp) {
      if (exp % 2) {
        *this *= rhs;
      }
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
};

struct SegTreeMOD {
    private :
    
    // 演算結果に影響しない0元
    // 最小値：inf, 最大値: -inf, sum:0, xor:0
    modint<MOD> ZERO;
    
    
    int n;          // 要素数
    vector<modint<MOD>> dat;  // セグメントtree配列
                    // dat[0] 　　　　　　: [0,n)の値
                    // i番目の数列（葉）   : dat[i + n - 1]
                    // dat[k]の子要素    : dat[ 2 * k + 1], dat[ 2 * k + 2]
                    //                    dat
                    // dat[k]の親要素    : dat[ (k - 1) / 2 ]

    vector<modint<MOD>> lazy; // 遅延評価配列
    
public:
    
    SegTreeMOD(int n_) {
        int x = 1;
        while(x < n_) {
            x *= 2;         //n以上の 2^m形式に変換
        }
        n = x;
        
        vector<modint<MOD>>dattmp (n * 2 - 1, ZERO); //セグメント木は、要素数 sz * 2 - 1の配列を準備
        dat = dattmp;
        vector<modint<MOD>>lazytmp(n * 2 - 1, ZERO); //遅延評価配列も同じ数準備
        lazy = lazytmp;
        
    }
    
    
    // 区間[a,b)を値xで更新、最大最小-> 遅延評価。和, XOR, その他-> 通常
    void update(int a, int b,  modint<MOD> x) {
        
            updateNolazy_forSum(a, b, x);
        
    }
    // dat[a]を値xで更新
    void update(int a,  modint<MOD> x) {
        update(a,a+1,x);
    }
    
    //区間[a,b)の値を取得するクエリ
     modint<MOD> query(int a, int b) { return query_sub(a, b, 0, 0, n); };
    
    //全区間の値を取得するクエリ
     modint<MOD> allquery() { return query_sub(0, n+1, 0, 0, n); };

    //lazy[k]に登録してあった値を、１階層下の子要素に伝播させて、自身の値も変更
    void eval(int k) {
        if(lazy[k].a == ZERO.a) return ;
        if(k < n -1) //kは末端ノード（葉）ではない
        {
            lazy[2 * k + 1] = lazy[k];
            lazy[2 * k + 2] = lazy[k];
        }
        dat[k] = lazy[k];
        lazy[k] = ZERO;
    }
    
private:
    void updateLazy_forMinMax(int a, int b,  modint<MOD> x, int k, int l, int r) {
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
    void updateNolazy_forSum(int i,  modint<MOD> x) { // i: 更新したい数列の位置（葉の位置）　x: 更新する値
        i += n - 1;                  // i番目の要素は i + n - 1の位置に格納
        dat[i] = x;
        while(i > 0) { //親をたどって値を更新していく
            i = (i - 1) / 2;
            dat[i] = choice(dat[i * 2 + 1], dat[i * 2 + 2] );
        }
    }
    
    //その時点で値を更新する
    void updateNolazy_forSum(int a, int b,  modint<MOD> x) { //区間[a,b)を値xで更新
        for(int i = a; i < b; i++) {
            updateNolazy_forSum(i,x);
        }
    }
    
private:
     modint<MOD> query_sub(int a, int b, int k, int l, int r) {
        eval(k);
        if(b <= l || r <= a)
            return ZERO;    //区間外
        if(a <= l && r <= b )
            return dat[k]; // 区間にすっぽり収まる
        
        //一部重なる
         modint<MOD> lv = query_sub(a, b, 2 * k + 1, l          , (r + l)/ 2 );
         modint<MOD> rv = query_sub(a, b, 2 * k + 2, (r + l) / 2, r );
        
        return choice(lv,rv);
    }
    
    
    void setMode(int mode_) {
        ZERO =  0;
    }
    
     modint<MOD> choice( modint<MOD> a,  modint<MOD> b) {
        return a + b ;
    }
    

};


// dp[i]: マスiにいる時のマスNへの回数の期待値
// dp[i] = (\Sigma_{j=0}^{A[i]}(dp[i+j])/(A[i]+1) + 1  
//  <=>  A[i]/(A[i]+1) * dp[i] = (\Sigma_{j=1}^{A[i]}(dp[i+j])/(A[i]+1) + 1  (dp[i]項の移動)
//  <=>  dp[i] = (A[i]+1)/A[i] *  ((\Sigma_{j=1}^{A[i]}(dp[i+j])/(A[i]+1) + 1 )
//  <=>  dp[i] = (\Sigma_{j=1}^{A[i]}(dp[i+j]) + (A[i]+1) )/A[i]
modint<MOD> dp [MAX_N];

void solve() {
  ll N; cin >> N;
  vector<modint<MOD>> A(N); 
  rep(i,N-1) {
    ll a; cin >> a;
    A[i+1] = a;
  }

  SegTreeMOD bit(N);
  dp[N] = 0;
  bit.update(N,0);
  for(int i = N-1; i > 0; i--) {
    dp[i] =  ((bit.query(i+1,i + A[i].a+1)) / A[i]) + ((A[i]+1) /A[i]);
    bit.update(i,dp[i]);
  }
  cout << dp[1].a << endl;

}

int main()
{
  solve();
	return 0;
}