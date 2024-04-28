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


#define INF (2147483647)
#define MINF (-2147483648)
#define INF_LL  (9223372036854775807LL)
#define MINF_LL (-9223372036854775808LL)
#define MOD 998244353

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

template<typename T>
struct BIT {

private:
  ll N;
  vector<T> bit;

public:
  BIT(ll N) : N(N), bit(N+1) {}

private:
  T queryFromZero(ll i) {
    T sum = 0;
    while(i > 0) {
      sum += bit[i];
      i -= i & -i;
    }
    return sum;
  }

public:
/*
   bit[i] = +v 及びその上位にvを加算する
*/
  void add(ll i, T v) {
    while(i <= N) {
      bit[i] += v;
      i += i & -i;
    }
  }

/*
  bit[i]...bit[j]の和
*/
  T query(ll i, ll j) {
    return queryFromZero(j) - queryFromZero(i-1);
  }
  
// bit[i]
  T query(ll i) {
    return bit[i];
  }
};

int main()
{
	ll N; cin >> N;
	vector<ll> A(N);
	vector<pair<ll,ll>> sortA(N);
	vector<ll> index(N);
	rep(i,N){ 
		cin >> A[i];
		sortA[i] = {A[i],i};
	}

	sort(sortA.begin(),sortA.end());

	rep(i,N) {
		index[sortA[i].second] = i+1;
	}

	BIT<ll> bitsum(N+2);
	BIT<ll> bitcnt(N+2);

	bitsum.add(index[N-1],A[N-1]);
	bitcnt.add(index[N-1],1);

	ll ans = 0;
	for(int i = N-2;i > -1; i--) {
		ll v   = bitsum.query(index[i],N);
		ll cnt = bitcnt.query(index[i],N);
		ans += v - A[i]*cnt;

		bitsum.add(index[i],A[i]);
		bitcnt.add(index[i],1);
	}
	out(ans)
	return 0;
}