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

using mint = modint998244353;//double;//modint998244353;

//aとbの最大公約数を計算
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}


int main()
{
	ll N; cin >> N;
	ll n = N;

	ll cnt2 =0, cnt3 = 0, cnt5 = 0;

	while(n%2 == 0){ 
		n /= 2;
		cnt2 ++;
	}
	while(n%3 == 0){
		n /= 3;
		cnt3 ++;
	}
	while(n%5 == 0){
		n /= 5;
		cnt5 ++;
	}

	if(n > 1) {
		//2,3,5以外の素因数が存在
		out(0)
		return 0;
	}

	mint dp[cnt2+1][cnt3+1][cnt5+1];
	rep(i,cnt2+1)rep(j,cnt3+1)rep(k,cnt5+1)dp[i][j][k] = 0;
	dp[cnt2][cnt3][cnt5] = 1;

	rev(i2,cnt2)rev(i3,cnt3)rev(i5,cnt5) {
		if(0 <= i2-1) 				dp[i2-1][i3][i5]   += dp[i2][i3][i5]/5; //2
		if(0 <= i3-1) 				dp[i2][i3-1][i5]   += dp[i2][i3][i5]/5; //3
		if(0 <= i2-2) 				dp[i2-2][i3][i5]   += dp[i2][i3][i5]/5; //4
		if(0 <= i5-1) 				dp[i2][i3][i5-1]   += dp[i2][i3][i5]/5; //5
		if(0 <= i2-1 && 0 <= i3-1) 	dp[i2-1][i3-1][i5] += dp[i2][i3][i5]/5; //6
	}

	out(dp[0][0][0].val())


	return 0;
}