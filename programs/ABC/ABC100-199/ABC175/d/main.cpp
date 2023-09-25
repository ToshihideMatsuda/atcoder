#include "bits/stdc++.h"
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


int main()
{
  ll N, K;cin >> N>> K;
  ll P[N+1],C[N+1];
  rep(i,N) cin >> P[i+1];
  rep(i,N) cin >> C[i+1];


  ll ans=MINF_LL;
  
  reps(i,1,N+1) {
    ll oneLoop = 0;
    ll oneLoopMax = C[P[i]];
    ll loop = 0;
    ll p = i;

    vector<ll> path = {-1};

    while(path.back() != i) {
      loop ++;
      p = P[p];
      oneLoop += C[p];
      
      oneLoopMax = MAX(oneLoopMax,oneLoop);
     // cout<<i<<":"<<p<<":"<<oneLoopMax<<":"<<oneLoop<<endl;

      if(path[0] == -1) path[0] = p;
      else path.push_back(p);
      
      if(loop == K) {
        ans = MAX(ans,oneLoopMax);
        goto next;
      }
    }

    if(oneLoop <= 0) {
      ans = MAX(ans,oneLoopMax);
      goto next;
    } else {
      
      p = P[i];
      ll sum=C[p];
      rep(j,loop){
      	
      	ll val= sum+ (K-1-j)/loop * oneLoop;
      	ans = MAX(ans,val);
      	
      	p=P[p];
      	sum+=C[p];
      }
      
    }

next:
    continue;
  }

  cout << ans;

	return 0;
}