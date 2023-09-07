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


#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


int main()
{
	ll n, m; cin >> n >> m;
	vector<pair<ll,ll>> h(n); 
	vector<ll> w(m); 
	rep(i,n) {
		ll H;
		cin >> H;
		h[i] = {H, 0};
	}
	h.push_back({0,0});
	h.push_back({INF_LL,0});
	rep(i,m) cin >> w[i];

	sort(h.begin(),h.end());
	rep(i,n+2) h[i].second = i;

	vector<ll> head(n+1,0),  back(n+2,0);

	for(int i = 1 ; i < n; i+= 2) {
		ll d = h[i+1].first - h[i].first;
		head[i+1] = head[i-1] + d;
	}

	for(int i = n ; i > 1; i-= 2) {
		ll d = h[i].first - h[i-1].first;
		back[i-1] = back[i+1] + d;
	}


	ll ans = INF_LL;
	rep(i,m) {
		pair<ll,ll> val = {w[i],0};
		auto idx = lower_bound(h.begin(),h.end(),val);
		auto [H,j] = *idx;
		if(j % 2 == 0) {
			idx --;
			tie(H,j) = *idx;
		}

		ans = MIN(ans,head[j-1] + abs(w[i] - H) + back[j+1] ) ; 
	}

	out(ans)



	return 0;
}