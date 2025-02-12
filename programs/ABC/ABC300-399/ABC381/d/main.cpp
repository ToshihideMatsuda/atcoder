#include <bits/stdc++.h> 
#include <atcoder/all>

using namespace atcoder;
using namespace std;
// 多倍長テンプレ（デバッグだとダメかも）
/* ---------------------- ここから ---------------------- */
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


#define INF  (2000000000000000001LL)
#define MINF (-2000000000000000001LL)
#define MOD 998244353

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


int main()
{
	ll N; cin >> N;
	vector<ll> A(N);
	rep(i,N) cin >> A[i];

	ll ans = 0;
	map<ll,ll> B;
	ll c = 0;
	ll S = -1;
	for(int i = 0; i < N-1; ) {
		if(A[i] == A[i+1]) {
			if(S == -1) {
				S = i;
			}
			if(B.count(A[i]) == true) {
				ll E = B[A[i]] + 1;
				for(ll j = S; j <= E; j ++) {
					B.erase(A[j]);
					c--;
				}
				S = E+1;
			}
				
			B[A[i]] = i;
			c += 2;
			i += 2;
			ans = MAX(ans,c);
			continue;
		} else if(0 < i && A[i-1] == A[i]){
			S = i-1;
			B[A[i-1]] = i-1;
			c = 2;
			B = map<ll,ll>();
			i ++;
			ans = MAX(ans,c);
		} else {
			S = -1;
			i ++;
			if(c > 0){
				B = map<ll,ll>();
				c = 0;
			}
		}
	}

	out(ans);



	return 0;
}

/*
14 
1 1 1 3 3 5 5 5 4 4 3 3 2 2

13
1 1 3 3 5 5 5 5 4 4 3 3 2 2


8
1 1 1 1 1 2 2 2  

12 
2 3 1 1 2 2 3 3 1 1 2 2


14
1 1 2 2 3 3 1 1 2 2 4 4 5 5


16
1 1 2 2 3 3 1 1 8 8 2 2 4 4 5 5

16
1 1 2 2 3 3 1 1 8 8 2 2 4 4 5 5 9 9 9 3 3 8 8 2 2 4 4 5 5 1 1
*/