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

set<ll> R[102][102][102];

int main()
{
	ll n; cin >> n;

	rep(i,n) {
		ll x,y,z,a,b,c;
		cin >> x >> y >> z >> a >> b >> c;
		x++;y++;z++;a++;b++;c++;

		reps(Y,y,b+1)reps(Z,z,c+1) {
			R[x][Y][Z].insert(i);
			R[a][Y][Z].insert(i);
		}	
		
		reps(X,x,a+1 ) reps(Z,z,c+1) {
			R[X][y][Z].insert(i);
			R[X][b][Z].insert(i);
		}

		reps(X,x,a+1 ) reps(Y,y,b+1) {
			R[X][Y][z].insert(i);
			R[X][Y][c].insert(i);
		}
	}
	set<ll> ans[n];
	vector<tuple<ll,ll,ll>> d = {
		{1,1,0},{1,-1,0},{-1,1,0},{-1,-1,0},
		{1,0,1},{1,0,-1},{-1,0,1},{-1,0,-1},
		{0,1,1},{0,1,-1},{0,-1,1},{0,-1,-1},
	};
	reps(X,1,102)reps(Y,1,102) reps(Z,1,102) {
		ll N = R[X][Y][Z].size();
		if(N >= 2) {
			auto v = R[X][Y][Z];


			for(auto i : R[X][Y][Z])for(auto j : R[X][Y][Z]) if(i != j && ans[i].count(j) == false) {
				for(auto v: d) {
					auto [dx, dy, dz] = v;
					if( R[X+dx][Y+dy][Z+dz].count(i) && R[X+dx][Y+dy][Z+dz].count(j)  ) {
						ans[i].insert(j);
						ans[j].insert(i);
						break;
					}
				}
			}
		}
	}
	rep(i,n) out(ans[i].size())
	return 0;
}