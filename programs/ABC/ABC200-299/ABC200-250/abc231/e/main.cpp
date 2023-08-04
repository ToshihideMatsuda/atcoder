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


typedef long long ll;
using namespace std;
vector<ll> A;
unordered_map<ll,unordered_map<int,ll>> memo;
 
ll getCoin(ll X, int N){
	if(N==0) return X;
	if(memo[X][N]>0) return memo[X][N];
 
    // X = Q * A[N] + R
    // X = (Q + 1) * A[N] - P 
    // <=>  P = A[N] - R
    ll R  = X%A[N];
    ll Q  = X/A[N];
	ll P  = A[N]-R;
	
	if(R == 0)  return Q;
	if(P == 0)  return Q+1;
 
	ll w1=  Q + 1LL + getCoin(P, N-1);
	// 1枚オーバーの場合
	ll w2 = Q       + getCoin(R, N-1);
	// 1枚少ない場合
	
	ll ans = min(w1,w2);
	memo[X][N]= ans;
	return ans;
}
 
int main(){
	int N;
	ll X;
	cin >> N >> X;
	
	A.resize(N);
	
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	
	cout << getCoin(X, N-1) <<endl;
    
    return 0;
}