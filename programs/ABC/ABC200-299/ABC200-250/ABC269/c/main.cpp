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


vector<ll> one;

void solve() {
  ll N; cin >> N;
  vector<ll> X;

  ll k = 0;
  while(N > 0) {
    if((N & 1) == 1) { one.push_back(k); }
    k++;
    N = N >> 1;
  }

  for(ll i = 0; i < 1 << one.size(); i++) {
    ll j = i;
    ll x = 0;
    ll k = 0;

    while(j > 0) {
      if((j & 1) == 1) 
        x += (1LL << one[k]);
      k++;
      j = j >> 1;
    }
    X.push_back(x);
  }
  sort(X.begin(),X.end());
  rep(i,X.size()) cout << X[i] << endl;



  

}


int main()
{
  solve();
	return 0;
}