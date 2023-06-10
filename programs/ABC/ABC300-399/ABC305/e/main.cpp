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
	ll N, M, K; cin >> N >> M >> K;
	rep(i,M) {
		ll a, b; cin >> a >> b;
		G[a].push_back(b); G[b].push_back(a);
	}


	vector<ll> H(N+1,-1);
	priority_queue<
		pair<ll,ll>, 
		vector<pair<ll, ll>>, 
		less<pair<ll,ll> >> Q;
	
	rep(i,K) {
		ll p,h; cin >> p >> h;
		Q.push({h,p});
		H[p] = h;
	}


	while(Q.size() > 0) {
		ll p,h;

		tie(h,p) = Q.top(); Q.pop();

		if(H[p] != h) continue;

		for(auto q: G[p]) if(H[q] < h-1) {
			H[q] = h-1;
			if(h-1 > 0) {
				Q.push({h-1,q});
			}
		}
		
	}

	ll cnt = 0;
	rep(i,N+1) if(H[i] > -1) cnt++;

	out(cnt)
	rep(i,N+1) if(H[i] > -1) {
		out0(i)
		out0(" ")
	}



	return 0;
}