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


void solve() {
  ll N, A, B; cin >> N >> A >> B;

  if(N < A) {
    cout << 0 << endl;
  } else if(A <= B) {
    // N = 10, A = 2, B = 3  -> 9
    cout << N - A + 1 << endl;
  } else { 
    // N = 10, A = 4, B = 2  -> 4
    // 4 2 1
    cout << (N/A - 1) * (B) + min(((N+1)%A),B) << endl;
  }


}


int main()
{
  solve();
	return 0;
}