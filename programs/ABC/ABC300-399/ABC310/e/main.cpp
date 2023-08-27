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




string s; 
ll n; 
ll  charAt(int n) {
	return (s[n] - '0');
};

ll f(ll i, ll j) {
	if(i == j) return charAt(i);
	return !(f(i,j-1) & charAt(j));
}

ll test() {
	ll ret = 0;
	rep(i,n) {
		reps(j,i,n) {
			ret += f(i,j);
		}
	}
	return ret;
} 

int main()
{
	cin >> n;cin >> s;

	out0("ans:")out(test())

	ll ans = 0;

	if(n == 1) {
		out(s);
		return 0;
	} else {


		ll first = 0;
		ll second = 0;
		ll third = 0;

		ll tmp = charAt(0);
		first = tmp;
		reps(i,1,n) {
			tmp = !(tmp & charAt(i));
			first += tmp;
		}
		
		tmp = charAt(1);
		second = tmp;
		reps(i,2,n) {
			tmp = !(tmp & charAt(i));
			second += tmp;
		}

		ans = first + second;

		reps(i,2,n) {
			


			ll tmp;
			if(i % 2 == 0) {
				tmp = first;
			} else {
				tmp = second;
			} 

			// first
			tmp -= charAt(i-2);
			tmp -= (int)!(charAt(i-2) & charAt(i-1));

			ans += tmp;
			
			if(i % 2 == 0) {
				first = tmp;
			} else {
				second = tmp;
			} 
		}

	}

	out(ans);





	return 0;
}