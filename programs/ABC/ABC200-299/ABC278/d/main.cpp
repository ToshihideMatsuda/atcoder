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

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

void solve() {
  ll N; cin >> N;
  ll base = 0;
  unordered_map<ll,ll> A;

  rep(i,N) {
    ll a; cin >> a;
    A[i+1] = a;
  }
  ll Q; cin >> Q;

  rep(i,Q) {
    ll t; cin >> t;
    if(t == 1) {
      ll x; cin >> x;
      base = x;
      unordered_map<ll,ll> B;
      A = move(B);
    } else if(t == 2) {
      ll i, x; cin >> i >> x;
      A[i] += x;
    } else {
      ll i; cin >> i;
      ll ans = base;
      if(A.count(i)) {
        ans += A[i];
      }
      cout << ans << endl;
    }
  }

}


int main()
{
  solve();
	return 0;
}