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


ll powM2[60];
vector<string> ans(60,"0");

void calc(ll N) {
	if(N == 0) {
		return;
	} else if(N > 0){
		ll sum = 0;
		rep(i,60) {
			if(0 < powM2[i]) sum += powM2[i];
			
			if(N <= sum) {
				ans[i] = "1";
				calc(N-powM2[i]);
				return;
			}
		}
	} else if(N < 0) {
		ll sum = 0;
		rep(i,60) {
			if(powM2[i] < 0) sum += powM2[i];
			
			if(sum <= N) {
				ans[i] = "1";
				calc(N-powM2[i]);
				return;
			}
		}

	}

}

int main()
{
	ll N; cin >> N;

	powM2[0] = 1;
	reps(i,1,60) powM2[i] = powM2[i-1] * (-2);

	calc(N);
	bool output = false;
	for(int i = 59;i >= 0; i--) {
		if(ans[i] == "1") output = true;
		if(output) out0(ans[i]);
	}
	if(output == false) out0(0)
	cout << endl;
	return 0;
}
