#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define max(a,b)   (a>b?a:b)
#define max3(a,b,c) max(a,max(b,c))
#define min(a,b)   (a<b?a:b)
#define min3(a,b,c) min(a,min(b,c))


#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}

vector<ll> G[MAX_N];
bool ch[MAX_N];
vector<pair<ll,ll>>T[3];

void dfs(ll u) {
  ch[u] = true;
  for(auto v : G[u]) {
    if(!ch[v]) {
      T[1].push_back({u,v});
      dfs(v);
    }
  }
}

void solve() {
  ll N, K;
  cin >> N >> K;
  string S;
  cin >> S;


  vector<ll> F;

  reps(i,1,sqrt(N)+1) if( N%i == 0 ) {
      F.push_back(i);
      F.push_back(N/i);
  }

  ll ans = N;

  for(ll f : F) {
    //i = f * q + r
      
    ll k = 0;
    rep(r, f) {

        int ch[26];
        rep(i,26) ch[i] = 0;

        rep(q, N / f){
            char s = S[q * f + r];
            ch[s - 'a'] ++;
        }

        ll kk = 0;
        rep(i,26) kk = max(kk, ch[i]);
        
        k += (N / f) - kk;

    }

    if(k <= K) {
        ans = min(ans, f);
    }
  }
  cout << ans << endl;
}


int main()
{
  solve();
	return 0;
}