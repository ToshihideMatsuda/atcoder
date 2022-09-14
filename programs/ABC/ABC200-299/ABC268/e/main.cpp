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
  ll N; cin >> N;
  vector<ll> p(N);
  rep(i,N) cin >> p[i];

  vector<ll> q(N);
  rep(i,N) {
    q[i] = (p[i] - i + N)%N;
    //cout << q[i] << " ";
  }

  ll L[3] = {0  , N/3 + 1, (2*N)/3 + 1};
  ll H[3] = {N/3, (2*N)/3, N};
  ll ans = INF_LL;
  rep(i,3) {
    ll l = L[i], h = H[i];
    while(l < h - 2) {
      ll m1 = (2*l+h)/3;
      ll m2 = (l+h*2)/3;

      ll mv1 = 0, mv2 = 0;
      rep(i,N) {
        ll v1 = (q[i] - m1 + N) % N;
        v1 = min(v1, abs(N - v1));

        ll v2 = (q[i] - m2 + N) % N;
        v2 = min(v2, abs(N - v2));

        mv1 += v1;
        mv2 += v2;
      }

      if(mv1 <= mv2) {
        h = m2;
      } else {
        l = m1;
      }
    }
    

    ll ans0 = INF_LL;
    reps(v,l,h+1) {
      ll tmp = 0;
      rep(i,N) {
        ll v1 = (q[i] - v + N) % N;
        v1 = min(v1, abs(N - v1));
        tmp += v1;
      }
      ans0 = min(ans0,tmp);
    }
    ans = min(ans, ans0);
  }

  cout << ans << endl;



}


int main()
{
  solve();
	return 0;
}