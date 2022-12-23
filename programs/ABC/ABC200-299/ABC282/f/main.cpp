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

ll pow2[13] = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 9999999999 };

void solve() {
  ll N; cin >> N;
  ll M = N*12; cout << M << endl;

  reps(l,1,N+1) {
    rep(i,12) {
      ll r = MIN(l + pow2[i] - 1, N);
      cout << l << " " << r << endl;
    }
  }

  ll Q; cin >> Q;
  rep(i,Q) {
    ll L, R; cin >> L >> R;
      ll a,b;
    if(L == R) {
      a=(L-1)*12 + 1 ;
      b = a;
    } else {
      ll lcnt = 0;
      while(L + pow2[lcnt+1] - 1 < R) {
        lcnt++;
      }

      a = (L-1)*12 + (lcnt + 1);
      
      ll rcnt = 0;
      while(L < R - (pow2[rcnt+1] -1) ) {
        rcnt ++;
      }
      ll R2 = R - (pow2[rcnt] - 1);
      b = (R2-1)*12 + (rcnt + 1);

    }
    cout << a << " " << b << endl;

  }
}


int main()
{
  solve();
	return 0;
}