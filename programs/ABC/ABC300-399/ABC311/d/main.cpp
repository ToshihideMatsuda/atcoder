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
#define pb(s) push(s)

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N (2*100000+5)


int main()
{
	ll n, m; cin >> n >> m;
	vector<string> s(n); rep(i,n) cin >> s[i];
	auto c = vector(2,vector(n,vector(m,false)));
	queue<tuple<ll,ll,ll>> Q;

	ll L = 1, R = 2, U = -1, D = -2;
	ll LR = 0, UD=1;
	Q.push({1,1,L});
	Q.push({1,1,R});
	Q.push({1,1,U});
	Q.push({1,1,D});
	c[LR][1][1] = true;
	c[UD][1][1] = true;

	while(Q.size() > 0) {
		auto [x,y,d] = Q.front();Q.pop();
		if(d == L){
			if(s[x-1][y]=='.') {
				Q.push({x-1,y,d});
				c[LR][x-1][y] = true;
			} else if(s[x-1][y] =='#' && c[UD][x][y] == false) {
				Q.push({x,y,U});
				Q.push({x,y,D});
			}
		}
		if(d == R){
			if(s[x+1][y]=='.') {
				Q.push({x+1,y,d});
				c[LR][x+1][y] = true;
			} else if(s[x+1][y] =='#' && c[UD][x][y] == false) {
				Q.push({x,y,U});
				Q.push({x,y,D});
			}
		}

		if(d == U){
			if(s[x][y-1]=='.') {
				Q.push({x,y-1,d});
				c[UD][x][y-1] = true;
			} else if(s[x][y-1] =='#' && c[LR][x][y] == false) {
				Q.push({x,y,L});
				Q.push({x,y,R});
			}
		}
		if(d == D){
			if(s[x][y+1]=='.') {
				Q.push({x,y+1,d});
				c[UD][x][y+1] = true;
			} else if(s[x][y+1] =='#' && c[LR][x][y] == false) {
				Q.push({x,y,L});
				Q.push({x,y,R});
			}
		}
	}

	ll ans = 0;
	rep(i,n) rep(j,m) if(c[LR][i][j] || c[UD][i][j]) ans++;
	out(ans)

	return 0;
}