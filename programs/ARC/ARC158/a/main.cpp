#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
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
#define out2(s) cout << s;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 59)
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N (2*100000+5)


int main()
{
	ll T; cin >> T;
	rep(i,T) {
		vector<ll> x0(3);
		rep(j,3) cin >> x0[j];
		sort(x0.begin(),x0.end());
		if((x0[0] % 2) == (x0[1] % 2) && (x0[0] % 2)  == (x0[2] % 2)  ) {

			ll ans = 0;
			{
			vector<ll> x(x0);
			ll d0 = x[2] - x[1];
			ll d1 = x[2] - x[0];
			ll d  = MIN(d1/4, d0/2);
			ans += d;

			x[1] += 2 * ans;
			x[0] += 4 * ans;
			sort(x.begin(),x.end());
			//x[2] == x[1] >= x[0]
			if(x[2] != x[1]) {
				if(x[1] == x[0]) {
					ans = -1;
					goto next;
				}
				x[0] += 4;
				x[1] += 2;
				ans += 1;
				sort(x.begin(),x.end());
			}

			ll n = x[2] - x[0];
			if(n % 6 == 0) {
				ans += (n/6) * 2;
				goto next;
			} else {
				ans = -1;
				goto next;
			}
			}

			next:
			ll ans2 = 0;
			{
			vector<ll> x(x0);
			ll d = x[1] - x[0];
			ll tmp = d/2;
			ans2 += tmp;
			x[0] += 4*tmp;
			x[1] += 2*tmp;
			
			if(x[2] < x[0] || x[2] < x[1]){
				ans2 = -1;
				goto end;
			}
			
			ll n = x[2] - x[0];

			if(n%6 == 0) {
				ans2 += (n/6) * 2;
				goto end;
			}else {
				ans2 = -1;
				goto end;
			}
			}
			end:
			if(ans2 == -1 && ans == -1) {
				out(-1)
			}
			else if(ans2 != -1 && ans != -1) {
				out(MIN(ans2,ans))
				}
			else {
				out(MAX(ans2,ans))
			}
		} else {
			out(-1)
		}
	}

	return 0;
}
