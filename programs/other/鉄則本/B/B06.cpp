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
  ll N ; cin >> N;
  vector<ll> A(N),S(N+1);
  S[0] = 0;
  rep(i,N) {
    cin >> A[i];
    S[i+1] = S[i] + A[i];
  }
  ll Q; cin >> Q;
  rep(i,Q) {
    ll l, r; cin >> l >> r;
    ll all = r - l + 1;
    ll sum = S[r] - S[l-1];
    if(sum == all - sum) cout << "draw" << endl;
    else if (sum > all - sum) cout << "win" << endl;
    else cout << "lose" << endl;

  }


}


int main()
{
  solve();
	return 0;
}