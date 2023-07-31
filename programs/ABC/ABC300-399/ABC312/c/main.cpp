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
	ll n, m; cin >> n >> m;
	vector<ll> a(n); rep(i,n) cin >> a[i];
	vector<ll> b(m); rep(i,m) cin >> b[i];

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	vector<pair<ll,ll> > A, B;
	A.push_back({0,0});
	B.push_back({0,0});
	rep(i,n) A.push_back({a[i], i+1});
	A.push_back({INF_LL, n+1});

	rep(i,m) B.push_back({b[i], i+1});
	B.push_back({INF_LL, m+1});

	ll lb = 0, ub = INF_LL;
	while(ub-lb >1) {
		ll mid = (ub + lb) / 2;

		// mid円で売ってもいい人の人数
		auto idx  = lower_bound(A.begin(), A.end(),  (pair<ll,ll> ){mid, INF_LL});
		ll Ax = (*idx).second - 1;
		
		// mid円で買ってもいい人の人数
		auto idx2 = lower_bound(B.begin(), B.end(), (pair<ll,ll> ){mid,-1});
		ll Bx = (m+1) - (*idx2).second;

		if(Bx <= Ax) {
			ub = mid;
		} else {
			lb= mid;
		}
	}

	out(ub)

	return 0;
}