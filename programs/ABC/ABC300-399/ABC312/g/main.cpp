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

ll n; 
vector<ll> pathSize[MAX_N]; // v1, v2, v3, ... vm
ll sum[MAX_N];              // v1 + v2 + v3, ... vm
ll twoProductSum[MAX_N];    // v1*(v2 + v3 + ... ) + ...
ll _ans[MAX_N];				// v1 * v2 * v3 + ...

void add(ll p, ll v) {
	if(pathSize[p].size() == 0 ) {
	} else if(pathSize[p].size() == 1 ) {
		twoProductSum[p] = v*sum[p];
	} else {
		_ans[p] += v*twoProductSum[p];
		twoProductSum[p] += v*sum[p];
	}
	sum[p] += v;
	pathSize[p].push_back(v);
} 

ll dfs(ll p, ll prev) {

	ll sum = 0;
	for(auto q : G[p]) if(prev != q) {
		ll v = dfs(q,p);
		add(p,v);
		sum += v;
	}
	if(n-1-sum > 0) {
		add(p,n-1-sum);
	}

	return sum + 1;
}

int main()
{
	cin >> n;
	readG(n-1);

	ll p = 0;
	reps(i,1,n+1) if(G[i].size() == 1) {
		p = i;
		break;
	}

	dfs(p,-1);

	ll ans = 0;
	reps(i,1,n+1) ans += _ans[i];
	out(ans)



	return 0;
}