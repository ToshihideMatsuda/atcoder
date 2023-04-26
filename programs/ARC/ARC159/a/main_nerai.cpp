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

#define MAX_N 100+5

ll N, M;//N頂点 M辺

 // グラフの隣接行列
 // 配列d[a][b]には頂点a,b間の辺のコストを入れておき、a=bの時は0を、a,b間の辺が存在しないときはINFを入れておく。
 //
 // rep(i,MAX_N) rep(j,MAX_N) d[i][j] = (i == j ? 0 : INF);
 // rep(i,M){
 //   ll a, b, c;
 //   cin >> a >> b >> c;
 //   d[a][b] = c;
 //   d[b][a] = c;
 // }

typedef vector<vector<ll> > mat;
mat make_mat(ll N, ll M){
    return vector<vector<ll> >(N,vector<ll>(M));
}


int main()
{
	ll N, K; cin >> N >> K;

	mat A = make_mat(N,N);
	rep(i,N) rep(j,N) cin >> A[i][j];
	
	ll Q; cin >> Q;

	rep(_,Q) {
		ll s, t; cin >> s >> t;
		s--; t--;
		s%=N, t%=N;
		ll ans = 0;
		set<ll> S;
		if(s == t) {
			if(A[s][s] == 1) {
				out(1)
				continue;
			} else {
				rep(i,N) if(A[s][i] == 1) S.insert(i);
				ans++;
			}
		} else {
			 S.insert(s);
		}

		rep(i,N+5) {
			set<ll> nxt;
			for(auto q : S) {
				if(q == t) {
					out(ans)
					goto next;
				} else {
					rep(i,N)if(A[q][i] == 1){
						nxt.insert(i);
					}
				}
			}
			S = nxt;
			ans ++;
		}

		out(-1)

		next:
		continue;
	}
	return 0;
}