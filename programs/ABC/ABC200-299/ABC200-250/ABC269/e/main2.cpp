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

ll query(ll A, ll B, ll C, ll D) {
    ll T=0;
    cout << "? " << A << " " << B << " " << C << " " << D << endl;
    cin >> T;
    return T;
}
void decide(ll X, ll Y) {
    cout << "! " << X << " " << Y << endl;
}

void solve(ll N) {
  ll X,Y;
  
  rep(i,2) {
    ll L = 0, U = N;
    while(L + 1 < U ) {
        ll M = (L + U) / 2;
        ll T = (i == 0) ? query(1,M,1,N) : query(1,N,1,M);
        if(T == -1) return;

        if(T < M) {
            U = M;
        } else {
            L = M;
        }
    }
    if(i==0) X = U; 
    else     Y = U;
  }


  decide(X,Y);
  return;
}


int main()
{
    ll N; cin >> N;
    solve(N);

    return 0;
}