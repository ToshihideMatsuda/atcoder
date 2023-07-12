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

#define MAX_N (20)


int main()
{
    ll N; cin >> N;
    vector<ll> X(N),Y(N),Z(N);
    rep(i,N) cin >> X[i] >> Y[i] >> Z[i];

    ll a = (1 << N) + 5;
    int dp[N][a];
    // dp[i][S] = 現在地がiかつ訪問済みの地点がSの場合のコストの最小値
    rep(i,N)rep(s, a) dp[i][s] = INF;
    dp[0][1] = 0;

    reps(visitNum,2,N+1) {
        for(int S = 0; S < (1 << N); S++) {
            set<ll> s;
            rep(i,N+1) if( ( S & (1<<i)) >0) s.insert(i);
            if(visitNum == s.size()) {
                rep(i,N) if(s.count(i)){
                    int T = S - (1 << i);
                    int d = INF;
                    for(auto j : s) if(j != i) {
                        int dif = abs(X[j] - X[i]) +  abs(Y[j] - Y[i]) + MAX(0, Z[j] - Z[i]);
                        d = MIN(d,dp[j][T] + dif);
                    }
                    dp[i][S] = d;
                }
            } 
        }
    }

    ll ans = INF_LL;
    rep(j,N) if(j !=0){
        ll dif = abs(X[j] - X[0]) +  abs(Y[j] - Y[0]) + MAX(0, Z[j] - Z[0]);
        ans = MIN(ans,dp[j][(1 << N) -1] + dif);
    }

    out(ans)


   


	return 0;
}