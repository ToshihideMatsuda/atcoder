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
  ll r1,c1,r2,c2; cin >> r1 >> c1 >> r2 >> c2;
  if(r1 == r2 && c1 == c2){
    cout << 0 << endl;
    return;
  } else if(
    r1 + c1 == r2 + c2 || 
    r1 - c1 == r2 - c2 || 
    abs(r1 - r2) + abs(c1 - c2) <=3) {
    cout << 1 << endl;
    return;
  } else if( 
    abs(r1 + c1) % 2 == abs(r2 - c2) % 2 ||
    abs(r1 - c1) % 2 == abs(r2 + c2) % 2 
    ){
    cout << 2 << endl;
    return;
  } else {
    reps(i,-3,3)reps(j,-3,3)if(abs(i) + abs(j) <= 3){
      ll r22 = r2 + i;
      ll c22 = c2 + j;
      if( r1 + c1 == r22 + c22 || 
          r1 - c1 == r22 - c22 || 
          abs(r1 - r22) + abs(c1 - c22) <=3){
        cout << 2 << endl;
        return;
      }
    }
  }
  cout << 3 << endl;
}


int main()
{
  solve();
	return 0;
}