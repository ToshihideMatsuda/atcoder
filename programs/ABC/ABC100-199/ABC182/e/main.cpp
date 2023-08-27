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
	ll h,w,n,m; cin >> h >> w >> n >> m;
	ll G[h+2][w+2];
	ll L[4][h+2][w+2];
	rep(i,h+2)rep(j,w+2) {
		G[i][j] = 0;
		rep(k,4) L[k][i][j] = 0;
	}


	rep(i,n) {
		ll a,b;
		cin >> a >> b;
		G[a][b] = 1;
	}
	rep(i,m) {
		ll c,d;cin >> c >> d;
		G[c][d] = -1;
	}

	// 0 U->D
	reps(i,1,h+1)reps(j,1,w+1) {
		if(G[i][j] == 0 && L[0][i-1][j] == 1)  L[0][i][j] = 1;
		else if(G[i][j] == 1) L[0][i][j] = 1;
	}

	// 1 D->U
	for(ll i = h; i >= 1;i--)reps(j,1,w+1) {
		if(G[i][j] == 0 && L[1][i+1][j] == 1)  L[1][i][j] = 1;
		else if(G[i][j] == 1) L[1][i][j] = 1;
	}

	// 2 L->R
	reps(i,1,h+1)reps(j,1,w+1) {
		if(G[i][j] == 0 && L[2][i][j-1] == 1)  L[2][i][j] = 1;
		else if(G[i][j] == 1) L[2][i][j] = 1;
	}

	// 3 R->L
	reps(i,1,h+1)for(ll j = w; j >= 1;j--) {
		if(G[i][j] == 0 && L[3][i][j+1] == 1)  L[3][i][j] = 1;
		else if(G[i][j] == 1) L[3][i][j] = 1;
	}

	ll ans = 0;
	reps(i,1,h+1){
		reps(j,1,w+1) rep(k,4) if(L[k][i][j] == 1) { 
			ans++; break;
		}
	}
	out(ans)

	return 0;
}