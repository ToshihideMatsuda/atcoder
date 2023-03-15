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

ll A[15][15];
int main()
{
	ll H, W; cin >> H >> W;
	rep(h,H)rep(w,W) cin >> A[h][w];

	ll ans = 0;
	ll  P = H+W-2;
	for(int i = 1; i < (1 << P); i++) {
		vector<ll> p;
		int j = i;

		ll h = 0;
		while(j > 0) {
			if((j & 1) >= 1){
				p.push_back(1);
				h ++;
			} else {
				p.push_back(0);
			}
			j >>= 1;
		}

		if(h == (H-1)) {
			while(p.size() < P ) p.push_back(0);

			set<ll> s;
			int h = 0,w = 0;
			s.insert(A[h][w]);
			for(auto k : p) {
				if(k == 1) {
					h ++;
				} else {
					w++;
				}
				s.insert(A[h][w]);
			}

			if(s.size() == P+1) {
				ans ++;
			}

		}
	}
	out(ans)
	return 0;
}
