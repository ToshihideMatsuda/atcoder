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
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N 2*100000+5
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

void solve() {
  ll N; string K; cin >> N >> K;

  string R;
  rep(i,K.size()) R.insert(R.begin(),K[i]);

  if(N < stoll(K) || stoll(R) < stoll(K)) {
    cout << 0 << endl;
    return;
  }

  set<string> seed;
  if(stoll(K) <= N) seed.insert(K);
  if(stoll(R) <= N) seed.insert(R);


  ll ans = 0;
  ll i = 0;
  while(true) {
    bool ok = false;
    for(string v : seed) {
      string s (i,'0');
      if(stoll(v + s) <= N ) {
        ans++;
        ok = true;
      }
    }
    if(ok == false) break;
    i++;
  }

  cout << ans << endl;
  


}


int main()
{
  solve();
	return 0;
}