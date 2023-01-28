#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) MIN(a,MIN(b,c))
#define out(s) cout << s << endl;
#define out2(s) cout << s;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

void solve() {
  ll N; cin >> N;
  vector<string> S(N);
  rep(i,N) cin >> S[i];
  vector<string> T(S);
  T.push_back("");
  T.push_back("{");
  sort(T.begin(),T.end());

  unordered_map<string,ll> mp;


  reps(i,1,N+1) {
    ll ans1=0;
    ll ans2 = 0;
    rep(j,MIN(T[i-1].size(),T[i].size())) if(T[i-1][j] == T[i][j]){ ans1 ++; } else break;
    rep(j,MIN(T[i+1].size(),T[i].size())) if(T[i+1][j] == T[i][j]){ ans2 ++;} else break;

    mp[T[i]] = MAX(ans1,ans2);
  }
  rep(i,N) {
    ll a = mp[S[i]];
    out(a)
  }
  
}


int main()
{
  solve();
	return 0;
}