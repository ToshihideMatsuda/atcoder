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
  ll N;cin >> N;
  char A[N][N];
  rep(i,N) rep(j,N) cin >> A[i][j];
  rep(i,N) rep(j,N) {
    if(i != j) {
      if(A[i][j] == 'D' && A[j][i] != 'D') {
        cout << "incorrect" << endl;
        return;
      } else if(A[i][j] == 'W' && A[j][i] != 'L') {
        cout << "incorrect" << endl;
        return;
      } else if(A[i][j] == 'L' && A[j][i] != 'W') {
        cout << "incorrect" << endl;
        return;
      }  
    }
  }

        cout << "correct" << endl;
}


int main()
{
  solve();
	return 0;
}