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
	ll H, W, D; cin >> H >> W >> D;

	pair<ll,ll> G[1 + H*W];
	vector A(H+1,vector(W+1,0));
	reps(h, 1, 1+H)reps(w, 1, 1+W) {
		ll a; cin >> a;
		G[a] = {h,w};
		A[h][w] = a;
	}

	ll q; cin >> q;
	vector<ll> L(q),R(q);
	rep(i,q) {
		cin >> L[i] >> R[i];
	}


	vector S(H+1,vector(W+1,0));
	reps(l,1,D+1) {
		ll i = l;
		auto[h, w] = G[i];
		while(i+D <= H*W) {
			i += D;
			auto [h1, w1] = G[i];
			S[h1][w1] = S[h][w] + (abs(h-h1) + abs(w-w1));
			h = h1;
			w = w1;
		}
	}


	rep(i,q) {
		auto[h, w] = G[L[i]];
		auto[h1, w1] = G[R[i]];
		
		ll ans = S[h1][w1] - S[h][w];
		out(ans)
	}


	return 0;
}