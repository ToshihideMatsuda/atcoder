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
#define mp(a,b) make_pair(a,b)


#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 200+5


// 多倍長テンプレ（デバッグだとダメかも）
/* ---------------------- ここから ---------------------- */
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
// 任意長整数型
using Bint = mp::cpp_int;
// 仮数部が10進数で1024桁の浮動小数点数型(TLEしたら小さくする)
using Real = mp::number<mp::cpp_dec_float<1024>>;
/* ---------------------- ここまで ---------------------- */


void solve() {
    ll N; cin >> N;
    ll C[9]; rep(i,9) cin >> C[i];

    ll minC = INF_LL; rep(i,9) minC = min(minC, C[i]);
    ll len = N/minC;

    string ans = "";

    rep(i,len) {
      for(int j = 8; j > -1; j --) 
      {
        if(minC * (len - 1 - i) + C[j] <= N) {
          //cout << j << endl;
          N -= C[j];
          ans.push_back((j + 1) + '0');
          break;
        }
      }
    }
    cout << ans << endl; 
}


int main()
{
  solve();
	return 0;
}