#include <bits/stdc++.h> 
#include <unordered_map>
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

ll get10Keta(ll N) {
  ll k = 0;
  ll tmp = N; 
  while(tmp > 0) {
    tmp /= 10;
    k++;
  }
  return k;
}

ll getTen(ll N) {
  ll ten = 1; 
  while(N > 0) {
    ten *= 10;
    N--;
  }
  return ten;
}

void solve() {
  ll N; cin >> N;
  ll ans = 0;
  reps(i,1,1000001) {
    ll k = get10Keta(i);
    ll ten = getTen(k);
    ll v = i + i * ten;
    if(N < v) break;
    ans++;
  }
  cout << ans << endl;
}


int main()
{
  solve();
	return 0;
}