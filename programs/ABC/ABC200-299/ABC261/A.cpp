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
  ll L1, R1,L2,R2; cin >> L1 >> R1 >> L2 >> R2;

  if(L1<= L2 && R2 <= R1) {
    cout << R2 - L2 <<endl;
    return;
  } else if(L2 <= L1 && R1 <= R2) {
    cout << R1 - L1 <<endl;
  } else if (R2 < L1 || R1 < L2) {
    cout << 0 <<endl;
  } else if(L2 <= L1 && L1 <= R2){
    cout << R2 - L1 <<endl;
  } else  {
    cout << R1 - L2 <<endl;
  }

}


int main()
{
  solve();
	return 0;
}