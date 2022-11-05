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



void solve() {
  ll N, L; cin >> N >> L;
  vector<ll> A(N); vector<char> B(N); 
  rep(i,N) cin >> A[i] >> B[i];

  ll ans = 0;
  rep(i,N) {
    if(B[i] == 'W') ans = MAX(ans,A[i]);
    else ans =  MAX(ans,L-A[i]);
  }

  cout << ans << endl;



}


int main()
{
  solve();
	return 0;
}