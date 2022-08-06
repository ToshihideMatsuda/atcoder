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


void debugBIT() {
  BIT tree(10);
  ll list[10] = {1,4,2,62,5,2,5,321,2,1};
  
  //sum[0] = 0, sum[1] = list[0], sum[2] = list[0] + list[1], sum[3] = list[0] + list[1] + list[2], ...
  ll sum[11];sum[0] = 0;

  reps(i,1,11) sum[i] = sum[i-1] + list[i-1];
  rep(i,10) tree.update(i+1,list[i]);


  reps(i,1,11){
    cout << "BIT:[1," << i <<"]=" << tree.query(i) << endl;
    cout << "Sum:[1," << i <<"]=" << sum[i] << endl;
  }

  cout << "--------" <<endl;

  cout << "update: list[3] += -10;" << endl;
  cout << "update: list[8] += 87;" << endl;

  cout << "--------" <<endl;

  ll d3 = -10, d8 = 87;
  list[3] += d3;
  list[8] += d8;

  tree.update(4,d3);
  tree.update(9,d8);

  reps(i,1,11) sum[i] = sum[i-1] + list[i-1];

  reps(i,1,11){
    cout << "BIT:[1," << i <<"]=" << tree.query(i) << endl;
    cout << "Sum:[1," << i <<"]=" << sum[i] << endl;
  }

  cout << "--------" <<endl;
  cout << "BIT:[5,8]=" << tree.query(5,8) << endl;
  cout << "Sum:[5,8]=" << sum[8] - sum[5-1] << endl;
  
}

//mergeソート（転置数取得
ll merge_cnt(vector<ll> &a) {
  ll n = a.size();

  if (n <= 1) {
    return 0;
  }

  ll cnt = 0;

  vector<ll> b(a.begin(), a.begin() + n / 2);
  vector<ll> c(a.begin() + n / 2, a.end());

  cnt += merge_cnt(b);
  cnt += merge_cnt(c);

  ll ai = 0, bi = 0, ci = 0;
  // merge の処理
  while (ai < n) {
    if (bi < (ll)b.size() && (ci == (ll)c.size() || b[bi] <= c[ci])) {
      a[ai++] = b[bi++];
    } else {
      cnt += n / 2 - bi;
      a[ai++] = c[ci++];
    }
  }
  return cnt;
}

void debugInversion() {
    vector<ll> list{1,4,2,62,5,2,5,321,2,1};

    rep(i,list.size()) cout << list[i] << ",";
    cout << endl;
    cout << "inverse_cnt:   " << inverse_cnt(list) << endl;
    cout << "merge_cnt:     " << merge_cnt(list) << endl;
  
    
    rep(i,list.size()) cout << list[i] << ",";
    cout << endl;
    cout << "inverse_cnt:   " << inverse_cnt(list) << endl;
    cout << "merge_cnt:     " << merge_cnt(list) << endl;


    list = {2,3,65,11,-2,3,7,323,1,23,51,3};
    rep(i,list.size()) cout << list[i] << ",";
    cout << endl;
    cout << "inverse_cnt:   " << inverse_cnt(list) << endl;
    cout << "merge_cnt:     " << merge_cnt(list) << endl;
}


int main()
{
  debugInversion();
	return 0;
}