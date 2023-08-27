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

using mint = modint1000000007;


int main()
{
	string S; cin >> S;

	ll N = S.size();

	vector<ll> LA(N,0), LQ(N,0);
	vector<ll> RC(N,0), RQ(N,0);

	rep(i,N){
		if(i > 0){
			LA[i] = LA[i-1];
			LQ[i] = LQ[i-1];
		}
		if(S[i] == 'A') LA[i] ++;
		if(S[i] == '?') LQ[i] ++;
	}

	rev(i,N-1){
		if(i < N-1){
			RC[i] = RC[i+1];
			RQ[i] = RQ[i+1];
		}
		if(S[i] == 'C') RC[i] ++;
		if(S[i] == '?') RQ[i] ++;
	}


	mint ans = 0;

	rep(i,N) {
		if(S[i] == 'B') ans += (LA[i] + LQ[i]) * (RC[i] + RQ[i]);
		if(S[i] == '?') {
			ans += (LA[i] + MAX(LQ[i]-1, 0)) * (RC[i] + MAX(RQ[i]-1,0));
		}
	}

	out(ans.val())




	return 0;
}