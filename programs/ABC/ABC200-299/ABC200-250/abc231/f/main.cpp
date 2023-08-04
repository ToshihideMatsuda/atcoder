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
	ll n; cin >> n;
	vector<ll> A(n), B(n);
	rep(i,n) cin >> A[i];
	rep(i,n) cin >> B[i];
	/**/

	// bの座標圧縮関数 fb
    unordered_map<ll, ll> fb;
    {
        vector<ll> tmpA(B);
        sort(tmpA.begin(), tmpA.end());
        rep(i, tmpA.size()) if(fb.count(tmpA[i]) == false)fb[tmpA[i]] = i+1;
    }

	vector<pair<ll,ll>> ab(n);
	rep(i,n) ab[i] = {A[i], -B[i]};

	sort(ab.begin(),ab.end());

	BIT<ll> bit(n);

	ll ans = 0;
	ll eqCnt = 0;
	rep(i,n) {
		auto [a,mb] = ab[i];
		ll b = fb[-mb];
		bit.add(b,1);
		//out(bit.query(b,n))
		ans += bit.query(b,n);

		if(i > 0) {
			auto [a_bf,mb_bf] = ab[i-1];
			if(a==a_bf && mb == mb_bf) {
				eqCnt++;
				ans += eqCnt;
			} else {
				eqCnt = 0;
			}

		}


	}

	out(ans);

	
	return 0;
}