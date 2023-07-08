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
	vector<ll> P(N+5);
	vector<vector<ll>> rP(N+5);
	reps(i,2,N+1) {
		ll p;
		cin >> p;
		P[i] = p;
		rP[p].push_back(i);
	}

	map<ll,ll> mp;
	rep(i,M) {
		ll x, y; cin >> x >> y;
		if(mp.count(x)) {
			mp[x] = MAX(mp[x],y);
		} else {
			mp[x] = y;
		}
	}

	queue<pair<ll,ll>> Q;
	vector<bool> ck(N+5,false);

	if(mp.count(1)) {
		ck[1] = true;
		Q.push({1,mp[1]});
	} else {
		Q.push({1,0});
	}

	while(Q.size() > 0) {
		auto q = Q.front(); Q.pop();
		for(auto p: rP[q.first]) {
			
			ll cur = MAX(0, q.second-1);
			if(mp.count(p)){
				cur = MAX(cur,mp[p]);
			}

			if(cur > 0 || q.second > 0) ck[p] = true;
			Q.push({p,cur});
			
		}

	}
	ll ans = 0;
	reps(i,1,N+1) if(ck[i]) ans ++;
	out(ans)


	return 0;
}