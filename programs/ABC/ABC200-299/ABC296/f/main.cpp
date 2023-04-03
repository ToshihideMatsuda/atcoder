#include <bits/stdc++.h> 
#include <atcoder/all>
using namespace std;
using namespace atcoder;

typedef long long ll;
typedef unsigned long long ull;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) MIN(a,MIN(b,c))
#define out0(s) cout << s;
#define out(s) out1(s)
#define out1(s) cout << s << endl;
#define out2(s,t) cout << s << t << endl;
#define out3(s,t,r) cout << s << t << r << endl;
#define out4(s,t,r,u) cout << s << t << r << u << endl;
#define out5(s,t,r,u,o) cout << s << t << r << u << o << endl;
#define outd(s) cout << setprecision(15) << s << endl;
#define pb(s) push_back(s)

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

ll primes [5]= { 7013813588750972951LL, 8929143633738088283LL, 4837909145654321621LL, 6819033938186690237LL, 5107328697654825071LL};
using mint = modint998244353;

int main()
{
	ll N; cin >> N;

  vector<ll> A(N);
  vector<ll> B(N);
  rep(i,N) cin >> A[i];
  rep(i,N) cin >> B[i];

  vector<ll> C;
  vector<ll> D;
  rep(i,N) if(A[i] != B[i]) {
    C.push_back(A[i]);
    D.push_back(B[i]);
  }
  
  ll size = C.size();
  rep(i,size) {
    C.push_back(C[i]);
  }

  for(auto prime:primes) {
    ll p = prime;
  set<ll> S;
  mint h = 0;
  mint pow  = 1;
  rep(i,size){
    h = (h * p + C[i]);
  }
  rep(i,size-1) {
    pow *= p;
  }

  S.insert(h.val());

  rep(i,size-1) {
    h = ( (h - pow * C[i]) * p + C[size+i]);
    pow *= p;
    S.insert(h.val());
  }

  mint h2 = 0;

  rep(i,size) {
    h2 = (h2 * p + D[i]);
  }
  
  if(S.count(h2.val())) {
  } else {
    out("No")
    return 0;
  }
  }

    out("Yes")
    return 0;


	return 0;
}