#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) max(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) min(a,MIN(b,c))

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N 2*100000+5
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

void solve() {
  ll N, K; cin >> N >> K;
  ll A[N], B[N], C[N], D[N]; 
  rep(i,N) cin >> A[i];
  rep(i,N) cin >> B[i];
  rep(i,N) cin >> C[i];
  rep(i,N) cin >> D[i];

  set<ll> AB;
  rep(i,N)rep(j,N) AB.insert(A[i] + B[j]);

  bool ok = false;
  rep(i,N)rep(j,N) {
    ll ans = K - (C[i] + D[j]);
    if(ans >= 2) {
        ok = ok || AB.count(ans);
    }
  }

  cout << (ok ? "Yes" : "No" ) << endl;

}


int main()
{
  solve();
	return 0;
}