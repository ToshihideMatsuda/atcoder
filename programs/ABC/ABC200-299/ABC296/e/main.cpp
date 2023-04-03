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
#define inV(A) for (auto &i: A) { cin >> i; }
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

ll N; 
vector<ll> from[MAX_N];
ll A[MAX_N];
ll d[MAX_N];

void addLoop(ll p) {
	d[p] = INF_LL;
	if( d[A[p]] != INF_LL) addLoop(A[p]);
}

void dfs(ll p, set<ll>& s) {
	if(d[p] != -1) return;

	if(s.count(p)) {
		//すでに登録あり（るーぷ）
		addLoop(p);
		return;
	} else {
		s.insert(p);

		if(from[p].size() == 0) {
			d[p] = 0;
			return;
		}

		ll tmp = 0;

		for(auto f : from[p]) {
			if(d[f] == -1) {
				dfs(f,s);
			}
			tmp = MAX(tmp,d[f]);
		}

		d[p] = tmp + 1;
	}

}

int main()
{
	cin >> N;
	reps(i,1,N+1) {
		ll a;
		cin >> a;
		from[a].push_back(i);
		A[i] = a;
	}

	rep(i,MAX_N) d[i] = -1;

	reps(i,1,N+1) {
		if(d[i] == -1) {
			set<ll> s;
			dfs(i,s);
		}
	}

	ll ans = 0;
	reps(i,1,N+1){
		if(d[i]>=INF) {
			ans ++;
		}
	}

	out(ans)

	return 0;
}