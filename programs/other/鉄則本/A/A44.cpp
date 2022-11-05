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

#define MAX_N 300000 + 5

bool mode = true;
ll N;
ll f(ll i) {
  if(mode) return i;
  else return N+1-i;
}


void solve() {
  ll Q; cin >> N >> Q;
  vector<ll> A(N+1); rep(i,N+1) A[i] = i;
  vector<ll> ans;
  rep(i,Q) {
    ll t; cin >> t;
    if(t == 1) {
      ll x,y; cin >> x >> y;
      A[f(x)] = y;
    } else if (t == 2) {
      mode = !mode;
    } else {
      ll x,y; cin >> x;
      ans.push_back(A[f(x)]);
    }
  }

  for( auto a: ans) cout << a << endl;



}


int main()
{
  solve();
	return 0;
}