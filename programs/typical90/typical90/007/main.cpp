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
  ll N; cin >> N;

  vector<ll> A(N); rep(i,N) cin >> A[i];
  sort(A.begin(),A.end());
  ll mi = A[0];
  ll ma = A[A.size()-1];
  
  ll Q; cin >> Q;
  vector<ll> B(Q);
  rep(i,Q)  cin >> B[i];
  for(auto b : B) {
    if(b <= mi) {
      cout <<  abs(mi - b) << endl;
    } else if(ma <= b) {
      cout <<  abs(ma -b) << endl;
    } else {
      auto idx = lower_bound(A.begin(),A.end(),b);
      ll v1 = *idx;
      ll v0 = *(--idx);
      cout <<  MIN(abs(v1 - b), abs(v0 - b)) << endl;
    }
  }
}


int main()
{
  solve();
	return 0;
}