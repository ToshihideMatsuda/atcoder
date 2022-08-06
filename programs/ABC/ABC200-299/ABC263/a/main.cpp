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

  ll c[14];

void solve() {
  ll a[5]; rep(i,5) cin >> a[i];
  rep(i,5) {
    c[a[i]]++;
  }

  bool ok3 = false;
  bool ok2 = false;
  rep(i,14) if(c[i] == 3) ok3 = true; else if(c[i] == 2) ok2 = true;

  if(ok3 && ok2) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }



}


int main()
{
  solve();
	return 0;
}