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

#define MAX_N (100+5)
vector<ll> G[MAX_N];

ll N, M; 


int main()
{
	cin >> N >> M;

	ll c = 1;
	vector<bool> visited(N+1);
	while(true) 
	{
		visited[c] = true;

		ll k; cin >> k;
		vector<ll> v(k);
		rep(i,k) {
			cin >> v[i];
			G[c].push_back(v[i]);
			G[v[i]].push_back(c);
		}

	for(auto u : v) if(u == N) {
		out(u)
		string s;
		cin >> s;
		exit(0);
	}

		bool skip = false;

		rep(i,k) if(visited[v[i]] == false){
			out(v[i]);
			c = v[i];
			skip = true;
			break;
		}

		if(skip == false) {
			//今回、与えられた点が全て到達済みの場合
			queue<ll> Q;
			vector<vector<ll>> path(N+1);
			Q.push(c);
			path[c] = {c};

			while(Q.size() > 0) {
				auto q = Q.front(); Q.pop();
				for(auto g: G[q]) if(path[g].size() == 0) {
					path[g] = path[q];
					path[g].push_back(g);
					Q.push(g);
				}
			}

			ll idx = -1;
			ll min = INF_LL;
			rep(i,N+1) if(visited[i] == false && G[i].size() > 0){
				if( path[i].size() < min ) {
					min = path[i].size();
					idx = i;
				}
			} 

			for(auto p : path[idx]) if(p != c && idx !=p){
				out(p)
				cin >> k;
				rep(i,k) {
					ll _v;
					cin >> _v;
				}
			}
			out(idx);
			c = idx;

		}
	}

	return 0;
}