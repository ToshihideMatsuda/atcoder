#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) max(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) min(a,MIN(b,c))

#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

void solve() {
   ll N, Q; cin >> N >> Q;
   vector<ll> A(N+1);rep(i,N) cin >> A[i+1];
   vector<pair<ll,ll>> B(N+2); // B[i] = A[i]よりも小さく、A[1],...,A[i-1],A[i]のいずれとも異なる要素の個数
   B[0] = {0,0};
   reps(i,1,N+1) {
    B[i] = {A[i] - 1 - (i-1),i};
   }
   B[N+1] = {INF_LL, N+1};
   rep(i,Q) {
    ll K; cin >> K;
    auto idx = lower_bound(B.begin(), 
                           B.end(), 
                           make_pair(K,-1LL));
    --idx;
    ll k0 = (*idx).first;
    ll n0 = A[(*idx).second];
   cout << n0 + (K-k0) << endl;


   }
}


int main()
{
  solve();
	return 0;
}