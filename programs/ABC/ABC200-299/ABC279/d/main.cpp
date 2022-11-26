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

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

double A, B;
double f(double x) {
  return A /sqrt(x + 1.0) + x * B; 
}

void solve() { cin >> A >> B;

  ll lb = 0, ub = INF_LL;
  while(lb+2 < ub) {
    ll mid1 = (2*lb+ub)/3;
    ll mid2 = (lb+2*ub)/3;

    if(f(mid1) < f(mid2) ) {
      ub = mid2;
    } else {
      lb = mid1;
    }
  }


  double ans = INF_LL;
  reps(i,lb,ub+1)
    ans = MIN(ans, f(i));

  cout << setprecision(1000) << ans << endl;

}


int main()
{
  solve();
	return 0;
}