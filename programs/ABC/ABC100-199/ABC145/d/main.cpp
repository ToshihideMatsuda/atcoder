#include <bits/stdc++.h> 
#include <atcoder/all>

using namespace atcoder;
using namespace std;
// 多倍長テンプレ（デバッグだとダメかも）
/* ---------------------- ここから ---------------------- */
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
// 任意長整数型
using bll = mp::cpp_int;
// 仮数部が10進数で1024桁の浮動小数点数型(TLEしたら小さくする)
using real = mp::number<mp::cpp_dec_float<1024>>;
/* ---------------------- ここまで ---------------------- */

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
#define MOD 1000000007

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


long long modPow(long long x, long long a) {
  if (x >= MOD) { x %= MOD; }
  if (a == 0) return 1;
  if (a == 1) return x;
  if (a % 2) return (x * modPow(x, a - 1)) % MOD;
  long long t = modPow(x, a / 2);
  return (t * t) % MOD;
}

long long modInv(long long x) {
  return modPow(x, MOD - 2);
}

ll modPerm(ll n, ll k) {
  ll ret = 1;
  for (ll i = 0; i < k; i++) {
    ret = (ret * (n - i)) % MOD;
  }
  return ret;
}

ll modComb(ll n, ll k) {
  ll a, b;
  a = modPerm(n, k);
  b = modPerm(k, k);
  return (a * modInv(b)) % MOD;
}



int main()
{
	ll X, Y; cin >> X >> Y;

	if((X+Y) % 3 != 0) {
		out(0)
		return 0;
	}


	// X <= Y

	ll cnt_1_2 = 0, cnt_2_1 = 0;

	while(X > 0 && Y > 0) {
		if(X < Y) {
			cnt_1_2++;
			X -= 1;
			Y -= 2;
		} else {
			cnt_2_1++;
			X -= 2;
			Y -= 1;
		}
	}

	if(X != 0 || Y != 0) {
		out(0)
		return 0;
	}
	

	ll ans = modComb(cnt_1_2+cnt_2_1,cnt_1_2);
	out(ans)

	
	return 0;
}