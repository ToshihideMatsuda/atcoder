#include <bits/stdc++.h> 
#include <unordered_map>
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
	ll L, N1, N2; cin >> L >> N1 >> N2;
	vector<ll> v1, l1, v2, l2;
	rep(i,N1) {
		ll v, l;
		cin >> v >> l;
		v1.push_back(v);
		l1.push_back(l);
	}

	rep(i,N2) {
		ll v, l;
		cin >> v >> l;
		v2.push_back(v);
		l2.push_back(l);
	}



	ll i1 = 0, i2 = 0;
	vector<pair<ll,ll>> v1_n, v2_n;

	ll ans = 0;

	while(i1 < N1 && i2 < N2) {
		if(l1[i1] == l2[i2]){
			v1_n.push_back({v1[i1], l1[i1]});
			v2_n.push_back({v2[i2], l2[i2]});
			i1++; i2++;
		} else if(l1[i1]<l2[i2]) {
			v1_n.push_back({v1[i1], l1[i1]});
			v2_n.push_back({v2[i2], l1[i1]});
			l2[i2] -= l1[i1];
			i1++;			
		} else {
			v1_n.push_back({v1[i1], l2[i2]});
			v2_n.push_back({v2[i2], l2[i2]});
			l1[i1] -= l2[i2];
			i2++;	
		}
	}

	rep(i,v1_n.size()) {
		if(v1_n[i].first == v2_n[i].first) {
			ans += v1_n[i].second;
		}
	}

	out(ans)

	return 0;
}

//10000000000
//10000000000