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
  ll N, M; cin >> N >> M;
  vector<ll> A(N); 
  rep(i,N) {
    cin >> A[i];
  }

  ll sum = 0;
  rep(i,N) sum += A[i];
  vector<pair<ll,ll>> AA(N);
  rep(i,N) AA[i] = {A[i] % M, A[i]};
 
  sort(AA.begin(),AA.end());
  vector<pair<ll,ll>> B(2*N+1);
  rep(i,N) {
    B[i] = AA[i];
    B[N+i] = AA[i];
  }
  B[2*N] = {INF_LL,INF_LL};
 

  ll l = 0, r = 0;
  ll ans = INF_LL;

  while(l < N) {
    ll msum = 0;
    if(r - l + 1 != N ) {
    while(B[r].first == B[r+1].first || (B[r].first +1)%M == (B[r+1].first)%M )   {
      r ++;
      if(r - l + 1 == N)
        break;
    }
    }

    reps(i,l,r+1) msum += B[i].second;

    ans = MIN(ans,sum - msum);

    l = r+1;
    r = r+1;
  }
  cout << ans << endl;

}


int main()
{
  solve();
	return 0;
}