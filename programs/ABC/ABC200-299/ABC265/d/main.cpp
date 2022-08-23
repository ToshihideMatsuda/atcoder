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
  ll N, P, Q, R;
  cin >> N >> P >> Q >> R;
  vector<ll> A(N); rep(i,N) cin >> A[i];
  vector<ll> S(N+1); // S[0] = 0l; S[1] = A[0]; S[2] = A[0] + A[1];
  S[0] = 0;
  rep(i,N) S[i+1] = S[i] + A[i];

  ll l0 = 0,r0 = 1;
  ll sum0 = A[0];

  while(r0 <= N) {
    if(sum0 == P+Q+R) {
      bool Pok = false;

      ll lb = l0, ub = r0;
      ll l1;
      while(lb + 1 < ub) {
        l1 = (lb + ub) / 2;
        ll v = S[l1] - S[l0];
        if(S[l1] - S[l0] == P) {
          Pok = true;
          break;
        } else if(S[l1] - S[l0] > P) {
          ub = l1;
        } else {
          lb = l1;
        }
      }

      if(Pok) {
        lb = l1, ub = r0;

        while(lb + 1 < ub) {
          ll mid2 = (lb + ub) / 2;
          ll v = S[mid2] - S[l1];
          if(S[mid2] - S[l1] == Q && S[r0] - S[mid2] == R) {
            cout << "Yes" << endl;
            return;
          } else if(S[mid2] - S[l1] > Q) {
            ub = mid2;
          } else {
            lb = mid2;
          }
        }
      }
      
      if(r0 == N) {
        break;
      }
      sum0 += A[r0];
      r0 ++;
    } else if (sum0 < P+Q+R) {

      if(r0 == N) {
        break;
      }
      sum0 += A[r0];
      r0 ++;
    } else { // P+Q+R < sum0
      sum0 -= A[l0];
      l0 ++;
    }
  }

  cout << "No" << endl;
}


int main()
{
  solve();
	return 0;
}