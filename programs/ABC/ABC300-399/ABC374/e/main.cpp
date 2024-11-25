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
#define INF_LL  (9223372036857LL)
#define MINF_LL (-9223372036854775808LL)
#define MOD 998244353

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


//aとbの最大公約数を計算
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

int main()
{
	ll N, X; cin >> N >>X;
	vector<tuple<ll,ll,ll,ll>> data;
	rep(n,N) {
		ll a,p,b,q; cin >> a >> p >> b >> q;
		data.push_back({a,p,b,q});
	}

	ll lW = 0;
	ll uW = INF;

	while(uW - lW > 1) {
		ll W = (uW + lW) / 2;

		ll x = 0;
		rep(i,N) {
			auto [A,P,B,Q] = data[i];

			ll a = B/gcd(A,B);; //機械の台数
			ll b = A/gcd(A,B);; //機械の台数

			ll R = 0;
			ll w = 0;
			if(b*Q < a*P) {
				//最大公約数の台数では、bのほうが生産能力が高い
				w += (W/(b*B) ) * (b*B);
				x += (W/(b*B) ) * (b*Q);
				R = W-w;
			} else  {
				//最大公約数の値段では、aのほうが生産能力が高い
				w += (W/(a*A) ) * (a*A);
				x += (W/(a*A) ) * (a*P);
				R = W-w;
			}

			if(X < x) break;

			//残りは全探索...
			ll Y = INF_LL;
			for(int i = 0; ; i ++) {
				if(R <= i*A) {
					Y = MIN(Y,i*P);
					break;
				}
				int j = ( R - (i*A) ) / B + ( ( ( R - (i*A) ) % B) == 0 ? 0 : 1 );
				Y = MIN(Y,i*P+j*Q);
			}

			x += Y;
			if(X < x) break;

		}

		if(X < x) {
			uW = W;
		} else {
			lW = W;
		}

		
	}
	out(lW)

	


	return 0;
}
//1000000000
//1000000000