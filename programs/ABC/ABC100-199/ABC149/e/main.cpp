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
	ll N, M; cin >> N >> M;
	vector<pair<ll,ll>> A(N);
	rep(i,N){
		ll a; cin >> a;
		A[i] = {a,0};
	}

	sort(A.begin(),A.end());
	rep(i,N) A[i].second = i;
	A.push_back({INF_LL, N });

	ll lb = 0, ub = INF_LL - 1;

	while(ub-lb > 1) {
		ll x = (lb + ub) / 2;

		ll cnt = 0;
		rep(i,N) {
			pair<ll,ll> v = {x - A[i].first,-1};
			auto idx = lower_bound(A.begin(), A.end(),v);
			cnt += N - (*idx).second;
		}

		if(M <= cnt) {
			lb = x;
		} else {
			ub = x;
		}
	}

	ll X = lb;;

	vector<ll> S(N);
	S[0] = A[0].first;
	reps(i,1,N) S[i] = S[i-1] + A[i].first;

	ll sum = 0;
	ll cnt = 0;
	rep(i,N) {
		ll lb = -1, ub = N;
		while(ub - lb > 1) {
			ll mid = (lb + ub) / 2;
			if(X <= A[i].first + A[mid].first) {
				ub = mid;
			} else {
				lb = mid;
			}
		}
		if(ub == N) {
			continue;
		}
		if(ub == 0) {
			sum += S[N-1] + A[i].first * N;
			cnt += N;
		} else {
			sum += S[N-1] - S[ub-1] + A[i].first * ( (N-1) - ub + 1);
			cnt += ( (N-1) - ub + 1);
		}
	}
	if(M < cnt) sum -= X*(cnt-M);

	out(sum)


	return 0;
}
