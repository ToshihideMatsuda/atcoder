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
	ll H, W, K; cin >> H >> W >> K;

	ll x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;

	vector<vector<char>> M(H+2);
	vector<char> S = vector(W+2,'@');
	M[0] = S;
	M[H+1] = S;
	reps(h,1,H+1) {
		M[h] = vector(W+2,'.');
		M[h][0] = '@';
		M[h][W+1] = '@';
		reps(w,1,W+1) cin >> M[h][w];
	}

	auto V = vector(H+2,vector(W+2, -1));

	ll dx[4] = { 1, -1, 0, 0};
	ll dy[4] = { 0, 0,  1, -1};

	queue<pair<ll,ll>> Q;
	Q.push({x1,y1});
	V[x1][y1] = 0;

	while(Q.size() > 0) {
		auto &[x,y] = Q.front(); Q.pop();

		rep(i,4) {
			reps(k,1,K+1){
				ll xx = x+k*dx[i];
				ll yy = y+k*dy[i];
				if(M[xx][yy] == '@') break;
				if(V[xx][yy] == -1  || V[x][y] + 1 < V[xx][yy]) {
					V[xx][yy] = V[x][y]+1;
					Q.push({xx,yy});
				}
			}
		}
	}

	out(V[x2][y2]);
	


	return 0;
}