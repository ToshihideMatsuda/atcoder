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
  ll N, K; cin >> N >> K;
  ll m = 0;
  vector<ll> A(N);rep(i,N){ 
    cin >> A[i];
    m = MAX(m,A[i]);
  }

  ll lb = 0, ub = m;
  while(lb + 1 < ub) {
    ll mid = (lb + ub) / 2;

    ll k = K;
    rep(i, N) {
      k -= (A[i] - 1) / mid;
    }
    if(k >= 0) {
      ub = mid;
    } else {
      lb = mid;
    }
  }

  cout << ub << endl;



}


int main()
{
  solve();
	return 0;
}