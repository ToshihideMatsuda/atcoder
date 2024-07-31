#include <bits/stdc++.h> 
#include <atcoder/all>

using namespace atcoder;
using namespace std;

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
#define INF_LL  (922337203685477580LL)
#define MINF_LL (-9223372036854775807LL)
#define MOD 998244353

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


int main()
{
    ll N; cin >> N;
	ll X, Y; cin >> X >> Y;
	vector<ll> A(N), B(N);  
	rep(i,N) cin >> A[i] >> B[i];
    
    auto dp = vector(N+1, vector(N+1, vector(X+1, INF_LL) ) );

    dp[0][0][0] = 0;

    reps(n,1,1+N) {
        dp[n][0][0] = 0;
        rep(m,n) {
            rep(i,X+1) {
                if(0<m) dp[n][m][i] = MIN(dp[n][m][i], dp[n-1][m][i]);
                if( dp[n-1][m][i] + B[n-1] <= Y && A[n-1] + i <= X) {
                    dp[n][m+1][A[n-1]+i] = MIN(dp[n][m+1][A[n-1]+i], dp[n-1][m][i] + B[n-1]);
                }
            }
        }
    }

    ll ans = 1;
    rep(m,N+1) {
        rep(i,X+1) {
            if(dp[N][m][i] <= Y ) {
                if(m == N) {
                    ans = N;
                } else {
                    ans = MAX(ans,m+1);
                }
            }
        }
    }
    out(ans)
    
    return 0;
}