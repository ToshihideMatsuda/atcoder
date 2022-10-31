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
  ll N; cin >> N;
  ll A[N+2]; A[0] = 0; A[N+1]=0;
  reps(i,1,N+1) cin >> A[i];
  ll Ls[N+2], Rs[N+2];
  rep(i,N+2) {
    Ls[i] = 0; Rs[i] = 0;
  }
  reps(i,1,N+1) Ls[i] = MAX(Ls[i-1], A[i]);
  revs(i,N,0)   Rs[i] = MAX(Rs[i+1], A[i]);

  ll D; cin >> D;
  rep(_,D) {
    ll L, R; cin >> L >> R;
    cout << MAX(Ls[L-1],Rs[R+1]) << endl;
  }



}


int main()
{
  solve();
	return 0;
}