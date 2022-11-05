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
  ll N; cin >> N;
  vector<ll> P(N);rep(i,N) cin >> P[i];
  vector<ll> Q(N);rep(i,N) Q[i] = P[i];

  vector<ll> tmp;

  revs(i, N-1, 0) if(P[i-1] < P[i]){
    //nop
    tmp.push_back(P[i]);
  } else {
    //初めての逆転
    tmp.push_back(P[i]);
    tmp.push_back(P[i-1]);
    sort(tmp.begin(),tmp.end());

    auto idx = lower_bound(tmp.begin(),tmp.end(),P[i-1]);
    idx--;
    Q[i-1] = *idx;
    ll ex = *idx;
    ll b = 0;
    reverse(tmp.begin(),tmp.end());
    reps(j,i,N) if(tmp[j-i+b] != ex){
      Q[j] = tmp[j-i+b];
    } else {
      b++;
      Q[j] = tmp[j-i+b];
    }
    break;
  }

  rep(i,N)
  cout << Q[i] << " ";



}


int main()
{
  solve();
	return 0;
}