#include <bits/stdc++.h> 

using namespace std;

#define debug false

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 



#define INF ((1 << 30) + (1 << 29) + (1 << 28) ) 
#define MINF (1 << 31)
#define INF_LL ((1LL << 60) + (1LL << 59) + (1LL << 58) )
#define MINF_LL (1LL << 63)
#define MOD 998244353

#if debug == true
    #define MAX_N 100 + 5
#else
    #define MAX_N 1500 + 5
#endif

// 冪乗計算 (x^n) % mod の計算
// mod <= 0 の場合には通常の冪乗計算（オーバーフロー無視）
ll pow(ll x, ll n, ll mod) {
    ll ret = 1;
    while (n > 0) {
        if (n & 1) {  // n の最下位bitが 1
            ret *=x;  // n の最下位bitが 1 ならば x^(2^i) をかける
            if(mod > 0) ret %=mod;
        }
        x *= x;       // nのビット数分だけ累乗する
        x %= mod;
        n >>= 1;      // n を1bit 左にずらして次のビットを見る
    }
    return ret;       // ret = ( x^n )% mod 
                      //     = (x^(10110...1)_2 % mod )みたいなイメージで計算していく
}


void solve(){
    ll N, L;
    cin >> N >> L;

    vector<string> S(N);
    vector< ll > A(27); // 0^L, 1^L, ..., 26^L

    rep(i, N) {
      cin >> S[i];
    }

    reps(i,1,27) {
      A[i]=pow(i,L,MOD);
    }

    ll ans;
    ans = 0;

    for(int v = 1; v < (1 << N); v++) {
      int w = v;
      int m = -1;
      string T;
      bool first = true;

      int idx = 0;

      while(w > 0) {
        if(w & 1 == 1) {
          if(first) {
            T = S[idx];
          }
          else {
            string U;
            set_intersection(T.begin(), T.end(), S[idx].begin(), S[idx].end(), back_inserter(U));
            T = U;
          }
          first = false;
          m *= -1;
        }
        w = w >> 1;
        idx ++;
      }
      ans += (m * A[T.size()]);
      ans += MOD;
      ans %= MOD;
    }

    cout << ans << endl;

}

int main(){
    solve();
    return 0;
}

