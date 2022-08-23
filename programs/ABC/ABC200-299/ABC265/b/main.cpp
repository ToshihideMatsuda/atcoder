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


void solve() {
  ll N, M, T;
  cin >> N >> M >> T;
  vector<ll> A(N); rep(i,N-1) cin >> A[i+1];
  rep(i,M) {
    ll x, y; cin >> x >> y;
    A[x] -= y;
  }

  rep(i,N){
    T -= A[i];
    if(T <= 0) {
      cout << "No" << endl;
      return;
    }
  }
  cout << "Yes" << endl;
}


int main()
{
  solve();
	return 0;
}