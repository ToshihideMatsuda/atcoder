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
  ll N, K; cin >> N >> K;
  vector<pair<ll,ll>> A(N); rep(i,N) {
    ll a;
    cin >> a;
    A[i] = {a, i};
  };
  sort(A.begin(),A.end());

  ll sum = 0;
  ll idx = 0;
  ll rem = N;
  ll lastVal = 0;

  while((A[idx].first-lastVal) * rem + sum < K) {
    sum += (A[idx].first-lastVal) * rem ;
    lastVal = A[idx].first;

    ll j = idx;
    while(A[idx].first == A[j].first) {
      A[j].first = 0;
      j++;
    }
    rem = N - j; 
    idx = j;
  }

  
  ll dif = (K - sum)/rem;
  sum += rem * dif;
  reps(j, idx, N)  A[j].first -= lastVal+dif;


  vector<ll> ans(N);
  rep(i,N) ans[A[i].second] = A[i].first;
  
  rep(i,N) if(ans[i] > 0) {
    if(sum == K) break;
    sum++;
    ans[i] -= 1;
  }

  rep(i,N) cout << ans[i] << " ";
  cout << endl;


}


int main()
{
  solve();
	return 0;
}