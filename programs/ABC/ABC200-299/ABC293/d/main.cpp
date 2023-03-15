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

pair<ll,ll> G[MAX_N][2];
ll ck[MAX_N];

ll f(char c) {
	if(c == 'R') return 0;
	return 1;
}
int main()
{
	ll N, M; cin >> N >> M;
	rep(i,MAX_N) {
		G[i][0] = {-1,-1};
		G[i][1] = {-1,-1};
		ck[i] = -1;
	}
	rep(i,M) {
		ll A, C; char B, D;
		cin >> A >> B >> C >> D;

		G[A][f(B)] = {C,f(D)};
		G[C][f(D)] = {A,f(B)};
	}

	ll l = 0;
	ll nl = 0;

	reps(n,1,N+1) {
		if(ck[n] > 0) continue;

		ck[n] = n;

		queue<pair<ll,ll>> Q;

		rep(i,2) {
			Q.push({n, 1});
			Q.push({n, 0});
		}

		while(Q.size() > 0) {
			ll a,from, c = -1, d;
			tie (a,from) = Q.front(); Q.pop();

			rep(to,2) {
				if(from != to && G[a][to].first != -1) {
					tie(c,d) = G[a][to];
					break;
				}
			}
			
			if(c == -1) continue;

			if(c == n) {
				l++;
				goto next;
			}
			ck[c] = n;
			Q.push({c,d});
		}

		nl++;

		next:
		continue;

	}

	out2(l)
	out2(" ")
	out(nl)

	return 0;
}
