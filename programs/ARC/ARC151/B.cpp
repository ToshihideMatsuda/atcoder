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

#define MAX_N 2*100000+5

ll euler_phi(ll n) {
  ll ret = n;
  for(ll i = 2; i * i <= n; i++) {
    if(n % i == 0) {
      ret -= ret / i;
      while(n % i == 0) n /= i;
    }
  }
  if(n > 1) ret -= ret / n;
  return ret;
}

long long modPow(long long x, long long a) {
  if (a == 0) return 1;
  if (a == 1) return x;
  if (a % 2) return (x * modPow(x, a - 1)) % MOD;
  long long t = modPow(x, a / 2);
  return (t * t) % MOD;
}

long long modInv(long long x) {
  return modPow(x, euler_phi(MOD) - 1);
}

void solve() {
  ll N, M;cin >> N >> M;
  vector<ll> P(N+1); 
  reps(i,1,N+1) cin >> P[i];

  // A_1,...,A_N として無条件にありうるパターンはM^N
  // 対称性より、A < A(P) と A(P) < A は同数
  // よって、A=A(P)の数をXとすると A < A(P) の数は　( M^N - X )/ 2

  // A=A(P)の数については、 i <-> P_i に辺をはったグラフGの連結成分数をCとする。
  // 一つの連結成分でとり得る値のパターン数は M通りなので　X=M^C
  // よって答えは( M^N - M^C )/ 2

  vector<ll> G[N+1];
  reps(i,1,N+1) {
    G[i].push_back(P[i]);
    G[P[i]].push_back(i);
  }

  ll c[N+1];
  rep(i,N+1) c[i] = -1;

  reps(i,1,N+1) {
    if(c[i] == -1) {
      queue<ll> Q;
      Q.push(i);
      while(Q.size() > 0) {
        auto q = Q.front();Q.pop();
        c[q] = i;
        for(auto g : G[q]) 
          if(c[g] == -1){
            Q.push(g);
          }
      }
    }
  }

  set<ll> s;
  reps(i,1,N+1) s.insert(c[i]);

  ll ans = (((modPow(M,N) - modPow(M,s.size()) + MOD) % MOD ) * modInv(2)) % MOD;
  cout << ans << endl;

}

int main()
{
  solve();
	return 0;
}