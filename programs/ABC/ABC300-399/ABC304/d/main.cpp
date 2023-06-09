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
	ll W, H; cin >> W >> H;
	ll N; cin >> N;
	vector<ll> P(N), Q(N);
	rep(i,N) cin >> P[i] >> Q[i];

	ll A, B;
	cin >> A;
	vector<ll> a(A);
	rep(i, A) cin >> a[i];

	cin >> B;
	vector<ll> b(B);
	rep(i,B) cin >> b[i];

	a.push_back(0);
	a.push_back(W);

	b.push_back(0);
	b.push_back(H);

	sort(a.begin(),a.end());
	sort(b.begin(),b.end());

	map<pair<ll,ll>,ll> cnt ;

	rep(i,N) {
		auto idxA = upper_bound(a.begin(),a.end(),P[i]);
		auto idxB = upper_bound(b.begin(),b.end(),Q[i]);
		cnt[{*idxA,*idxB}] ++;
	}

	ll min = INF_LL;
	if(cnt.size() == (A+1)*(B+1) ) {
		for(auto p : cnt) min = MIN(min, p.second);
	} else {
		min = 0;
	}

	ll max =0;
	for(auto p : cnt) max = MAX(max, p.second);


	out3(min," ", max)



	return 0;
}