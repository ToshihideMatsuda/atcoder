
typedef long long ll;

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
