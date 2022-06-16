#include <bits/stdc++.h> 
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

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}


void solve() {
    ll X, A, D, N;
    cin >> X >> A >> D >> N;

    ll ans = 0;

    // 交差は正に変換
    if(D < 0) {
        A = A + (N-1) * D;
        D *= -1;
    }

    if(X <= A) {
        ans = A - X;
    } else if(A + (N-1) * D <= X) {
        ans = X - ( A + (N-1) * D );
    } else  {
        ans = min((X - A) % D, D - (X - A) % D); 
    }
    cout << ans << endl;


}


int main()
{
  solve();
	return 0;
}