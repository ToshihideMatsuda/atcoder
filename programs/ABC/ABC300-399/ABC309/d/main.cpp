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

#define MAX_N (150000+5)
vector<ll> G1[MAX_N];
vector<ll> G2[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }


int main()
{
	ll N1,N2,M; cin >> N1 >> N2 >> M;
	rep(i,M) {
		ll a, b;
		cin >> a >> b;
		if(a <= N1) {
			G1[a].push_back(b);
			G1[b].push_back(a);
		} else {
			a -= N1;
			b -= N1;

			G2[a].push_back(b);
			G2[b].push_back(a);
		}
	}

	ll max = -1;
	queue<ll> Q;
	vector<ll> ck(MAX_N,-1);
	{
	Q.push(1);
	ck[1] = 0;
	while(Q.size() > 0) {
		auto q = Q.front(); Q.pop();
		for(auto g:G1[q]) if(ck[g] == -1) {
			ck[g] = ck[q] + 1;
			Q.push(g);
		}
	}

	reps(i,1,N1+1) max = MAX(max,ck[i]);
	}

	ll max2 = -1;
	{
		reps(i,0,MAX_N) ck[i] = -1;

	Q.push(N2);
	ck[N2] = 0;
	while(Q.size() > 0) {
		auto q = Q.front(); Q.pop();
		for(auto g:G2[q]) if(ck[g] == -1) {
			ck[g] = ck[q] + 1;
			Q.push(g);
		}
	}
	reps(i,1,N2+1) max2 = MAX(max2,ck[i]);
	}


	out(max + max2 + 1)

	return 0;
}