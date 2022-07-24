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

void solve() {
  ll N, C; cin >> N >> C;
  vector<ll> A(N), T(N);
  rep(i,N) cin >> T[i] >> A[i];

  ll zero = 0;
  ll one  = 1;

  rep(i,60) {
    one  = one << 1;
    one += 1;
  }

  vector<ll> Z(N+1);
  vector<ll> O(N+1);
  Z[0] = 0; O[0] = one;

  rep(i,N) {
    if(T[i] == 1) {
      Z[i+1] = Z[i] & A[i];
      O[i+1] = O[i] & A[i];
    } else if(T[i] == 2) {
      Z[i+1] = Z[i] | A[i];
      O[i+1] = O[i] | A[i];
    } else if(T[i] == 3) {
      Z[i+1] = Z[i] ^ A[i];
      O[i+1] = O[i] ^ A[i];
    }
  }

  vector<ll> CC(N+1);
  CC[0] = C;
  rep(i,N) {
    ll tmp = CC[i];
    ll newC = 0;
    for(ll k = 32; k > -1 ; k --) {
      ll one = 1LL << k;
      if((tmp & one) > 0) {
        newC += (O[i+1] & one);
        if((O[i+1] & one) > 0) {
          int i = 0;
        }
      } else {
        newC += (Z[i+1] & one);
        if((Z[i+1] & one) > 0) {
          int i = 0;
        }
      }
    }
    CC[i+1] = newC;
  }

  reps(i,1,N+1) cout << CC[i] << endl;





}


int main()
{
  solve();
	return 0;
}