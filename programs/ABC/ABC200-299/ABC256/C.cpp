#include <bits/stdc++.h> 
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

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}


void solve() {
  ll h[3],w[3];
  rep(i,3) cin >> h[i];
  rep(i,3) cin >> w[i];
  ll ans = 0;

  reps(i0, 1, h[0] - 1) {
    reps(j0, 1, h[0] - i0) {
      ll k0 = h[0] - i0 - j0; //h0 ok

      reps(i1, 1, h[1] - 1) {
        ll i2 = w[0] - ( i0 + i1); 
        if(i2 > 0) { // w0 ok
          reps(j1, 1, h[1] - i1) {
            ll j2 = w[1] - (j0 + j1); 
            if(j2 >0) {  // w1 ok
              ll k1 = h[1] - i1 - j1; //h1 ok
              ll k2 = w[2] - (k0 + k1); 
              if(k2 > 0) {  // w2 ok
                if(i2 + j2 + k2 == h[2]) {
                  ans ++;
                }

              }
            }
          }
        }
      }
    } 
  }
  cout << ans << endl;
}


int main()
{
  solve();
	return 0;
}