#include <bits/stdc++.h> 
#include <atcoder/all>

using namespace atcoder;
using namespace std;
// 多倍長テンプレ（デバッグだとダメかも）
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
#define MINF_LL (-9223372036854775807LL)
#define MOD 998244353

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


int main()
{
	ll N, Q; cin >> N >> Q;
	map<ll,ll> mp;
	vector<ll> a(N); rep(i,N) {
		cin >> a[i];
		mp[a[i]]++;
	}
	a.push_back(MINF_LL);
	a.push_back(INF_LL);
	sort(a.begin(), a.end());
	rep(i,Q) {
		ll b, k; cin >> b >> k;
		if(k <= mp[b]) {
			out(0) continue;
		}

		ll lb = 0, ub = 2L << 35;
		while(ub - lb > 1) {
			ll mid = (lb + ub)/2;
			ll l = b - mid - 1;
			ll r = b + mid + 1;

			auto low = upper_bound(a.begin(),a.end(),l);
			auto high = lower_bound(a.begin(),a.end(),r);
			high--;

			
			ll cnt = abs(distance(low,high))+1;
			if(*high < *low) cnt = 0;
			if(k <= cnt) {
				ub = mid;
			} else {
				lb = mid;
			}

		}

		out(ub);

	}
	return 0;
}