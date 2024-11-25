#include <bits/stdc++.h> 
#include <atcoder/all>

using namespace atcoder;
using namespace std;
// 多倍長テンプレ（デバッグだとダメかも）

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) MIN(a,MIN(b,c))
#define out0(s) cout << s;
#define out(s)  cout << s << endl;
#define outd(s) cout << setprecision(15) << s << endl;
#define pb(s) push_back(s)
/*
	vector<ll> X = {4,7,3,1,7,9,4};
	SORT(X, <)
	OUT(X,",") //1,3,4,4,7,7,9,

	SORT(X, >)
	OUT(X," ") //9 7 7 4 4 3 1
*/
#define SORT(A,R) std::sort((A).begin(),(A).end(), [](auto const& x, auto const& y) { return x R y; });
#define OUT(A,separate) for(auto a : A) { cout << a << separate; }


#define INF (2147483647)
#define MINF (-2147483648)
#define INF_LL  (9223372036854775807LL)
#define MINF_LL (-9223372036854775808LL)
#define MOD 998244353

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }





double dis(ll a, ll b, ll c,ll d) {
	return sqrtl( (a-c)*(a-c) + (b-d)*(b-d) );
}

int main()
{
	ll N; double T, S; cin >> N >> S >>T;
	vector<tuple<ll,ll,ll,ll>> ABCD;
	rep(i,N) {
		ll a, b,  c, d; cin >> a >> b >> c >> d;
		ABCD.push_back({a,b,c,d});
	}


	vector<ll> P;
	rep(i,N) P.push_back(i);

	double ans = 1e100;
	do {

		for(int i = 0; i < (1 << N);i ++) {
			double tmp = 0;
			ll x=0, y = 0;
			vector<ll> t(N,0);
			rep(j,N)if((i & (1 << j)) > 0)t[P[j]] = 1;

			rep(j,N) {

				auto [a,b,c,d] = ABCD[P[j]];
				if(t[P[j]] == 1) {
					tmp += dis(x,y,a,b)/S;
					tmp += dis(a,b,c,d)/T;
					x = c;
					y = d;
				} else {
					tmp += dis(x,y,c,d)/S;
					tmp += dis(a,b,c,d)/T;
					x = a;
					y = b;

				}
			}

			ans = MIN(tmp,ans);


		}
	} while(next_permutation(P.begin(),P.end()));
	
	outd(ans)

	
	return 0;
}