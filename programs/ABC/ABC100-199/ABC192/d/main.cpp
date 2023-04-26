#include <bits/stdc++.h> 
#include <unordered_map>
// 多倍長テンプレ（デバッグだとダメかも）
/* ---------------------- ここから ---------------------- */
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;
// 任意長整数型
using Bint = mp::cpp_int;

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


Bint f(string X, ll d) {
	Bint ans = 0;
	Bint ten = 1;
	rev(i,X.size()-1) {
		ans += (X[i] - '0');
		ans *= ten;
		ten *= d;
	}
	return ans;
}


int main()
{
	string X; cin >> X;
	ll M; cin >> M;

	ll d = 0;
	rep(i,X.size()) {
		d = MAX( (X[i] - '0') ,d);
	}

	if(M < f(X,d+1)) {
		out(0)
		return 0;
	}

	ll lb = d+1, ub = M+1;

	while(ub - lb > 1) {
		ll mid = (lb + ub) / 2;
		if(f(X,mid) <= M ) {
			lb = mid;
		} else {
			ub = mid;
		}
	}
	out(lb - d)

	return 0;
}