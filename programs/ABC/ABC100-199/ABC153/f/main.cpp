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
	ll N, D, A; cin >> N >>D >>A;
	vector<pair<ll,ll>> XH;
	rep(i,N) {
		ll X, H; cin >> X >> H;
		XH.push_back({X,H});
	}

	sort(XH.begin(),XH.end());
	XH.push_back({INF_LL,INF_LL});

	vector<ll> Damage(N+10);

	ll ans = 0;
	rep(i,N) {
		ll X, H;
		tie(X,H) = XH[i];
		Damage[i+1] += Damage[i];

		H  -= Damage[i+1];
		ll count = 0;
		if(H > 0) count = (H/A) + ((H%A) > 0  ? 1 : 0 );

		Damage[i+1] += count * A;


		pair<ll,ll> p = {X+2*D+1,-1};
		auto idx = lower_bound(XH.begin(), XH.end(), p);
		auto d = distance(XH.begin(),idx);
		Damage[d+1] -= count * A;

		ans += count;

	}
	out(ans);
	return 0;
}