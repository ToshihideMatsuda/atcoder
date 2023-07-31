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
	ll n, m; cin >> n >> m;
	vector<ll> C[3],tmp;
	rep(i,n) {
		ll t, x; cin >> t >> x;
		C[t].push_back(x);
	}

	if(m - C[0].size() > 0) {
		ll t = m-C[0].size();
		rep(i,t) {
			C[0].push_back(0);
		}
	}

	vector<ll> i(3,0);
	ll sum =0;
	sort(C[0].begin(),C[0].end());
	sort(C[1].begin(),C[1].end(),greater<ll>());
	sort(C[2].begin(),C[2].end(),greater<ll>());

	ll N = C[0].size();
	rep(j,m) {
		sum += C[0][N-1-j];
		i[0] = N-1-j;
	}

	while(true){
		rep(j,3)if(i[j]==C[j].size()){
			goto end;
		}

		ll x = C[2][i[2]++];

		ll dif = 0;
		dif -= C[0][i[0]++];
		while(x--) {
			rep(j,2)if(i[j]==C[j].size())break;
			
			if(C[1][i[1]] > C[0][i[0]]) {
				dif += C[1][i[1]++] - C[0][i[0]++];
			} else {
				break;
			}
		}

		if(dif > 0){
			sum += dif;
			continue;
		} else {
			goto end;
		}
	}
end:
	out(sum);




	return 0;
}