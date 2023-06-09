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


int main()
{
	ll N, M; cin >> N >> M;
	vector<ll> A(N);
	vector<ll> mp[M+1];
	rep(i,M+1) mp[i] = {};

	vector<ll> dist;
	vector<ll> start;

	rep(i,N) {
		cin >> A[i];
		rep(_,A[i]) {
			ll s; cin >> s;

			if(mp[s].size() > 0) {
				for(auto j:mp[s]) {
					G[i].push_back(j);
					G[j].push_back(i);
				}
			}

			mp[s].push_back(i);

			if(s == 1) {
				start.push_back(i);
			}

			if(s == M) {
				dist.push_back(i);
			}
	
		}
	}

	if(dist.size() == 0 || start.size() == 0) {
		out(-1)
		return 0;
	}


	ll c[N];
	rep(i,N)c[i] = -1;

	queue<ll> Q;
	for(auto s : start) {
		Q.push(s);
		c[s] = 0;
	}

	while(Q.size() > 0) {
		auto q = Q.front(); Q.pop();

		for(auto j : G[q]) if(c[j] == -1){
			c[j] = c[q] + 1;
			Q.push(j);
		}
	}

	ll ans = INF_LL;

	for(auto d : dist) {
		ans = MIN(ans, c[d]);
	}


	if(ans == INF_LL) {
		out(-1)
	} else {
		out(ans);
	}

	return 0;
}