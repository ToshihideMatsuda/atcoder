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


ll cntmex(set<ll>& s, ll l, ll r) 
{
	ll mex = 3;
	rep(i,3) {
		if(!s.count(i)) {
			mex = i;
			break;
		}
	}

	return mex * l * r;
}

int main()
{
	ll N; cin >> N; 
	vector<ll> A(N);
	rep(i,N) cin >> A[i];
	string S; cin >> S;

	auto cntM = vector<vector<ll>>(N,vector<ll>(3,0));
	auto cntX = vector<vector<ll>>(N,vector<ll>(3,0));
	if(S[0] == 'M') {
		cntM[0][A[0]] ++;
	}
	reps(i,1,N) {
		rep(j,3) cntM[i][j] = cntM[i-1][j];
		if(S[i] == 'M') {
			cntM[i][A[i]] ++;
		}
	}

	if(S[N-1] == 'X') {
		cntX[N-1][A[N-1]] ++;
	}
	rev(i,N-2) {
		rep(j,3) cntX[i][j] = cntX[i+1][j];
		if(S[i] == 'X') {
			cntX[i][A[i]] ++;
		}
	}

	ll ans = 0;
	reps(i,1,N-1) {
		if(S[i] == 'E') {
			ll e = A[i];
			ll tmp = 0;
			rep(m,3)rep(x,3) {
				if(cntM[i][m]> 0  && cntX[i][x] > 0) {
					set<ll> s = {m,e,x};
					tmp += cntmex(s,cntM[i][m],cntX[i][x]);
				}
			}
			ans += tmp;
		}
	}

	out(ans);

	return 0;
}