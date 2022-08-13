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


template<typename T>
struct BIT {
  ll N;
  vector<T> bit;
  BIT(ll N) : N(N), bit(N+1) {}

  void update(ll i, T v) {
    while(i <= N) {
      bit[i] += v;
      i += i & -i;
    }
  }

  T query(ll i) {
    T sum = 0;
    while(i > 0) {
      sum += bit[i];
      i -= i & -i;
    }
    return sum;
  }

  T query(ll i, ll j) {
    return query(j) - query(i-1);
  }
  
};

// 可変配列 a の転置数を返却
// BITを使用することでO(NlogN) で動作
// ロジックは https://qiita.com/wisteria0410ss/items/296e0daa9e967ca71ed6 を参照
ll inverse_cnt(vector<ll> & a) {

    // aの座標圧縮関数 f:a.element -> 1 ~ a.size()
    unordered_map<ll, ll> f;
    {
        vector<ll> tmpA(a);
        sort(tmpA.begin(), tmpA.end());
        rep(i, tmpA.size()) f[tmpA[i]] = i+1;
    }

    // 解
    ll inversion = 0;
    BIT<ll> bit(a.size());
    
    rep(i, a.size()) {
        // a[i]に対する前方の正置数
        ll t_ = bit.query(f[a[i]]);
        // a[i]に対する前方の転置数
        ll t = i - t_;

        // 転置数を加算
        inversion += t;
        bit.update(f[a[i]], 1);
    }

    return inversion;

}


void solve() {
  string S; cin >> S;

  string T = "atcoder";
  vector<ll> sv;

  rep(i,S.size()) {
    rep(j,T.size()) if(S[i] == T[j]) sv.push_back(j);
  }

  cout << inverse_cnt(sv) << endl;

}


int main()
{
  solve();
	return 0;
}