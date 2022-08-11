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

#define MAX_N 2*100000+5


void solve() {
  ll N, L; cin >> N >> L;

  ll azi = 0;
  ll azi_min = INF_LL;
  reps(i,1,N+1) {
    azi += L + i - 1;
    if(abs(L + i - 1) < abs(azi_min) ) {
      azi_min = L + i - 1;
    }
  }
  cout << azi - azi_min << endl;
}


int main()
{
  solve();
	return 0;
}