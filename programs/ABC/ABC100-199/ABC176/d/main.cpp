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

vector<ll> dx = {1 ,-1, 0, 0 };
vector<ll> dy = {0 ,0,  1, -1};

string S[1000+4];
ll     T[1000+4][1000+4];

void bfs(set<pair<ll,ll>>& target, ll i, set<pair<ll,ll>>& next){
		queue<pair<ll,ll>> Q;
		for(auto t:target) {
			Q.push(t);
		}


		while(Q.size() > 0) {
			ll qh, qw; 
			tie(qh, qw) = Q.front(); Q.pop();
			T[qh][qw] = i;
			rep(i,4) {
				if(	T[qh + dx[i]][qw + dy[i]] == -1 &&
					S[qh + dx[i]][qw + dy[i]] == '.') {
					Q.push({qh + dx[i],qw + dy[i]});
				} else if(S[qh + dx[i]][qw + dy[i]] == '#'){
					next.insert({qh,qw});
				} 
			}
		}
}

int main()
{
	ll H, W; cin >> H >> W;
	ll ch, cw; cin >> ch >> cw;
	ll dh, dw; cin >> dh >> dw;

	rep(h,1000+4)rep(w,1000+4) T[h][w] = -1;
	rep(h,1000+4) {
		string s(1000+4,'#');
		S[h] = s;
	}

	reps(h,2,H+2)reps(w,2,W+2) cin >> S[h][w];

	set<pair<ll,ll>> edge = {{ch+1,cw+1}};

	set<pair<ll,ll>> nextEdge;
	bfs(edge, 0, nextEdge);
	edge = nextEdge;

	while(edge.size() > 0) {
		set<pair<ll,ll>> nextEdge;
		for(auto e: edge){
			ll h, w;
			tie(h,w) = e;
			reps(i,-2,3) reps(j,-2,3) if(T[h + i][w+ j] == -1 && S[h + i][w+ j] == '.' ) {
				set<pair<ll,ll>> s = {{h + i, w + j}};
				bfs(s, T[h][w]+1, nextEdge);
				if(T[dh+1][dw+1] > 0) {
					out(T[dh+1][dw+1]);
					return 0;
				}
			}
		}
		edge = nextEdge;
	}

	out(T[dh+1][dw+1]);


	return 0;
}