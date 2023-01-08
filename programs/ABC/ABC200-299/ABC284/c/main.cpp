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
#define out(s) cout << s << endl;
#define out2(s) cout << s;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N (100+5)
vector<ll> G[MAX_N];
ll ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

void solve() {
  ll N, M; cin >> N >> M;
  readG(M);
  rep(i,MAX_N) ck[i] = -1;
  
  queue<ll> Q;
  ll ans = 0;
  reps(i,1,N+1){
    if(ck[i] == -1) {
      ans++;
      Q.push(i);
      while(Q.size() > 0) {
        ll q = Q.front();Q.pop();
        for(auto g:G[q]) 
        if(ck[g] == -1) {
          ck[g] = i;
          Q.push(g); 
        }
      }
    }
  }
  out(ans);
}


int main()
{
  solve();
	return 0;
}