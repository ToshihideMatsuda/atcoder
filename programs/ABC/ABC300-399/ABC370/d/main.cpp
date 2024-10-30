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






int main()
{
	ll H, W; cin >> H >> W;
	ll Q; cin >> Q;

	set<ll> C[H+1];
	set<ll> R[W+1];
	reps(i,1,H+1){
		reps(j,1,W+1) C[i].insert(j);
		C[i].insert(-1);
		C[i].insert(INF_LL);
	}
	reps(i,1,W+1){
		reps(j,1,H+1) R[i].insert(j);
		R[i].insert(-1);
		R[i].insert(INF_LL);
	}


	while(Q--) {
		ll r,c; cin >> c >> r;

		if(C[c].count(r)) {
			C[c].erase(r);
			R[r].erase(c);
		} else {
			{
				auto k = C[c].lower_bound(r);
				k--;
				ll v = *k;
				if(v != -1) {
					C[c].erase(k);
					R[v].erase(c);
				}
			}
			{
				auto k = C[c].lower_bound(r);
				ll v = *k;
				if(v != INF_LL) {
					C[c].erase(k);
					R[v].erase(c);
				}
			}

			{
				auto k = R[r].lower_bound(c);
				k--;
				ll v = *k;
				if(v != -1) {
					R[r].erase(k);
					C[v].erase(r);
				}
			}
			{
				auto k = R[r].lower_bound(c);
				ll v = *k;
				if(v != INF_LL){
					R[r].erase(k);
					C[v].erase(r);
				}
			}
		}
	}

	ll ans = 0;

	reps(h,1,H+1)reps(w,1,W+1)if(C[h].count(w) && R[w].count(h)) {

		ans ++;
	}
	out(ans)



	
	return 0;
}