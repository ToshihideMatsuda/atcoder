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
	vector<string> S(H + 10);
	rep(i,H+10) {
		string s("*",W+10);
		S[i] = s;
	}
	rep(i,H) {
		string s;
		cin >> s;
		S[i+5] = "*****" + s + "*****";
	}

	vector<char> ch = {'s','n','u','k','e'};
	ll dx[8] = {1,0,-1,0,1,1,-1,-1};
	ll dy[8] = {0,1,0,-1,1,-1,1,-1};


	vector<pair<ll,ll>> ans;

	reps(h,5,H+5)reps(w,5,W+5) {
		rep(k,8) {
			bool ok = true;
			rep(i,5) if(S[h+dx[k]*i][w+dy[k]*i] != ch[i]) ok = false;
			if(ok) {
				rep(i,5) ans.push_back({h+dx[k]*i,w+dy[k]*i});
				break;
			}
		}
	}

	rep(i,ans.size()) {
		out0(ans[i].first-4)
		out0(" ")
		out(ans[i].second-4)
	}



	return 0;
}