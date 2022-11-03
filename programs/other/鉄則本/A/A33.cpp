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

#define MAX_N 300000 + 5



/*
** Nim の Solver
** Nimとは: 先手と後手に分かれて、石を1個以上1つの山から取る。
**         取れる手がなくなった方（全ての山に石がない状態で手番が回ってくる）が負け
** input:   N, A[1], ..., A[N]
** output:  true: 先手必勝, false: 後手必勝
**         A[1] xor ... xor A[N] = 0 の場合、後手必勝　 （負け状態）
**         A[1] xor ... xor A[N] != 0 の場合、先手必勝　（勝ち状態）
** 
** easy-proof: 負け状態からは全ての手で勝ち状態に遷移する。（xorのどこかのビットが立つため）
**             <=> 自分が負け状態になると、もう相手を負け状態にはできない。
** 
**             勝ち状態からは負け状態に持ち込む手がある。（xorビットが立っている値をとある山からxorする）
**             <=> 自分が勝ち状態になると、必ず相手を負け状態にできる
*/
bool solveNim(vector<ll> &A) {

  ll ans = 0;
  for(auto a : A) ans ^= a;

  if(ans == 0) {
    return false; // 後手必勝
  } else {
    return true; // 先手必勝
  }

}


int main()
{
  ll N; cin >> N;
  vector<ll> A(N); rep(i,N) cin >> A[i]; 
  if(solveNim(A)) cout << "First";
  else cout << "Second";
	return 0;
}