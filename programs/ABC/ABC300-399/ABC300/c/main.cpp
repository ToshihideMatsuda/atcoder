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
	ll H, W; cin >>  H >> W;
	ll N = MIN(H,W);
	vector<vector<char>> C(H+2, vector<char>(W+2));
	rep(h,H+2)rep(w,W+2)C[h][w] = '.';
	reps(h,1,H+1)reps(w,1,1+W) cin >> C[h][w];

	vector<ll> ans(N+1);

	reps(h,2,H) {
		reps(w,2,W) {
			if( C[h][w] == '#' && 
				C[h-1][w-1] == '#' && 
				C[h-1][w+1] == '#' && 
				C[h+1][w-1] == '#' && 
				C[h+1][w+1] == '#'
			) {
				ll i = 0;
				while( 
					C[h+i][w+i] == '#' && 
					C[h-i][w+i] == '#' && 
					C[h+i][w-i] == '#' && 
					C[h-i][w-i] == '#') i ++;
				i--;
				ans[i] ++;

			}
		}
	}

	reps(i,1,1+N) {
		out0(ans[i])
		out0(" ")
	}


	return 0;
}