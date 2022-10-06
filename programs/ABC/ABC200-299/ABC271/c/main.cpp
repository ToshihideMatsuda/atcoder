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
  ll N; cin >> N;

  bool A[N + 5]; rep(i,N+5) A[i] = false;

  ll notUse = 0;
  rep(_,N) {
    ll a; cin >> a;
    if(a > N+1) notUse ++;
    else if(A[a]) notUse ++;
    else {
      A[a] = true;
    }
  }
  ll ans = 0;
  ll e = N+1;
  while(ans < e) {
    if(A[ans+1]) 
      ans ++;
    else {
      if(notUse < 2)  { 
        bool ok = false;
        while(ans < e) {
          if(A[e--]) {
            notUse++;
            if(notUse == 2) {
              ok = true;
              break;
            }
          } 
        }

        if(!ok) break;
      }
      notUse -= 2;
      ans ++;

    }
  }

  cout << ans << endl;
}


int main()
{
  solve();
	return 0;
}