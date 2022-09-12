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
  ll mod = INF_LL;
  vector<ll> A(N); 
  priority_queue<ll,vector<ll>,less<ll>> Q;
  rep(i,N){
    cin >> A[i];
    mod = min(A[i],mod);
  }

  bool exist = false;

  rep(i,N) if(exist) {
    Q.push(A[i]);
  } else {
    if(A[i] == mod){
      exist = true;
    } else {
      Q.push(A[i]);
    }
  }

  ll cnt = 0;
  while(Q.size() > 0) {
    cnt++;
    auto q = Q.top(); Q.pop();
    ll p = q % mod;
    if(p == 0) {
      continue;
    } else {
      Q.push(mod);
      mod = p;
    }
  }
  cout << cnt << endl;

}


int main()
{
  solve();
	return 0;
}