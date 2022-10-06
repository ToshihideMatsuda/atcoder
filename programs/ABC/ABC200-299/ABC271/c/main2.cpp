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
  deque<ll> A;
  set<ll> s;
  rep(i,N) {
    ll a; cin >> a;
    if(s.count(a)) {
      A.push_back(INF_LL);
    } else {
      A.push_back(a);
      s.insert(a);
    }
  }
  sort(A.begin(),A.end());

  ll ans = 0;
  while(A.size() > 0) {
    ll f = A.front();A.pop_front();

    while(ans + 1 < f) {
      if(A.size() == 1) {
        ans++;
        goto end;
      } else if(A.size() == 0){
        goto end;
      }
      rep(i,2) A.pop_back();
      ans++;
    }
    ans ++;
    continue;
  }

  end : 


  cout << ans << endl;
}


int main()
{
  solve();
	return 0;
}