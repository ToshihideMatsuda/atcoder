#include <bits/stdc++.h> 
#include <atcoder/all>
using namespace atcoder;
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) MIN(a,MIN(b,c))
#define out0(s) cout << s;
#define out(s) out1(s)
#define out1(s) cout << s << endl;
#define out2(s,t) cout << s << t << endl;
#define out3(s,t,r) cout << s << t << r << endl;
#define out4(s,t,r,u) cout << s << t << r << u << endl;
#define out5(s,t,r,u,o) cout << s << t << r << u << o << endl;
#define outd(s) cout << setprecision(15) << s << endl;
#define pb(s) push_back(s)

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

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
	ll N, M; cin >> N >> M;
	vector<tuple<ll,ll,ll>> A;
	rep(i, N) rep(j,M) {
		ll a; cin >> a;
		A.push_back({a,i+1,j+1});
	}
	sort(A.begin(), A.end());

	ll ans = 0;
	BIT<ll> B(N);
	for(auto aa : A) {
		ll a, n, m;
		tie(a, n, m) = aa;

		ans += (B.query(n+1,N)+(N-n)*m);
		B.add(n,1);
	}
	out(ans )


	return 0;
}