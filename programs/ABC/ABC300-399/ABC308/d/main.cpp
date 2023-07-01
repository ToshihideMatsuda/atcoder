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
	ll H, W; cin >> H >> W;
	vector<string> S(H+2);
	string s = "";
	rep(i,W+2) s += "$";
	
	S[0] = s;
	S[H+1] = s;
	reps(i,1,H+1){ 
		string t;
		cin >> t;
		S[i] = "$" + t + "$";
	}

	string T = "snuke";
	if(S[1][1] != 's') {
		out("No")
		return 0;
	}

	ll dx[4] = {1,-1,0,0};
	ll dy[4] = {0,0,1,-1};
	queue<tuple<ll,ll,ll>> Q;
	set<pair<ll,ll>> visited;
	Q.push({1,1,0});
	visited.insert({1,1});
	while(Q.size() > 0) {
		ll h, w, i;
		tie(h,w,i) = Q.front(); Q.pop();
		if(h == H && w == W) {
			out("Yes")
			return 0;
		}

		char nx = T[(i+1)%5];

		rep(j,4) {
			if(S[h + dx[j]][w+dy[j]] == nx && visited.count({h + dx[j], w+dy[j]}) == false) {
				visited.insert({h + dx[j], w+dy[j]});
				Q.push({h + dx[j], w+dy[j], (i+1)%5});
			}
		}

	}

	out("No")
	return 0;
	return 0;
}