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
    ll A, B; cin >> A >> B;
    A--;
    ll rB = B, rA = A;

    if(B % 4 == 0) {
    } else if (B % 4 == 3) {
        rB ^= (B-1)^(B-2)^(B-3);
    } else if (B % 4 == 2) {
        rB ^= (B-1)^(B-2);
    } else if (B % 4 == 1) {
        rB ^= (B-1);
    }

    if(A < 0) {
        rA = 0;
    } else if(A % 4 == 0) {
    } else if (A % 4 == 3) {
        rA ^= (A-1)^(A-2)^(A-3);
    } else if (A % 4 == 2) {
        rA ^= (A-1)^(A-2);
    } else if (A % 4 == 1) {
        rA ^= (A-1);
    }

    cout << (rB^rA) << endl;

}


int main()
{
  solve();
	return 0;
}