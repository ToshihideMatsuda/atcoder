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
	ll N, K; cin >> N >> K;
	ll A[N]; rep(i,N) cin >> A[i];
	ll L=0, R=0;
	ll s = 0; 
	ll l = 0;
	ll all = N*(N+1)/2;
	rep(i,N-1) {
		ll small = 0;
		ll large = 0;

		reps(j,i+1,N) if(A[j] < A[i]) small ++;
		reps(j,i+1,N) if(A[i] < A[j]) large ++;

		if((K - s) <= small) {
			L = i;
			vector<pair<ll,ll>> B;
			reps(j,i,N) if(A[j] < A[i])	B.push_back({A[j], j});
				
			sort(B.begin(),B.end());
			R = B[(K - s) -1].second;
			break;
		} else if((all - l) - K < large ) {
			L = i;
			vector<pair<ll,ll>> B;
			reps(j,i+1,N) if(A[i] < A[j]) B.push_back({A[j], j});
			sort(B.begin(),B.end(),greater<pair<ll,ll>>());
			R = B[all - l - K].second;
			break;
		} else {
			s += small;
			l += large;
		}
	}
	
	for(int i = 0  ; i <  L; i++) { out0(A[i])out0(" "); }
	for(int i = R  ; i >= L; i--) { out0(A[i])out0(" "); }
	for(int i = R+1; i <  N; i++) { out0(A[i])out0(" "); }

	return 0;
}