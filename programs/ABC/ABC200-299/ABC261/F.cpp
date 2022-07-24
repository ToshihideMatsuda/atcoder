#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define max(a,b)   (a>b?a:b)
#define max3(a,b,c) max(a,max(b,c))
#define min(a,b)   (a<b?a:b)
#define min3(a,b,c) min(a,min(b,c))

#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5


struct BIT {
  ll N;
  vector<ll> bit;
  BIT(ll N) : N(N), bit(N+1) {}

  void update(ll i, ll v) {
    while(i <= N) {
      bit[i] += v;
      i += i & -i;
    }
  }

  ll query(ll i) {
    ll sum = 0;
    while(i > 0) {
      sum += bit[i];
      i -= i & -i;
    }
    return sum;
  }

  ll query(ll i, ll j) {
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
    BIT bit(a.size());
    
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
  ll N; cin >>N;
  vector<ll> C(N), X(N);
  rep(i,N) cin >> C[i];
  rep(i,N) cin >> X[i];

  ll all = inverse_cnt(X);
  unordered_map<ll,vector<ll>> mp;
  rep(i,N) mp[C[i]].push_back(X[i]);
  
  ll color = 0;
  for(auto idx = mp.begin(); idx != mp.end(); idx++) {
    color += inverse_cnt((*idx).second);
  }


  cout << all - color << endl;

}


int main()
{
  solve();
	return 0;
}