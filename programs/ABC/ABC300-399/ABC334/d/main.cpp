#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <unordered_map>
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
#define out(s) cout << s << endl;
#define out0(s) cout << s;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N (2*100000+5)



int main()
{
	ll n, q; cin >> n >> q;
	
	vector<ll> r(n);
	rep(i,n) cin >> r[i];

	sort(r.begin(), r.end());
	vector<ll> s(n+2);
	s[0] = 0;
	rep(i,n) s[i+1] = s[i] + r[i];
	s[n+1] = INF_LL;
	while(q--) {
		ll x;
		cin >> x;

		ll lb = 0, ub = n+1;
		while(ub-lb > 1) {
			ll mid = (ub+lb)/2;
			if(s[mid] <= x) {
				lb = mid;
			} else {
				ub = mid;
			}
		}
		out(lb)
	}

	return 0;
}
