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

ll S[MAX_N];

void solve() {
  ll N; cin >> N;
  rep(i,N) {
    ll l, r;
    cin >> l >> r;
    S[l] = S[l] + 1;
    S[r] = S[r] - 1;
  }

  ll tmp = 0;
  reps(i, 1, MAX_N) {
    bool in = tmp > 0;
    tmp += S[i];
    S[i] = tmp;

    if(in) {
      if(tmp == 0) {
        cout << i  << endl;

      }
    } else {
      if(tmp > 0) {
        cout << i << " ";
      }

    }
  }


}


int main()
{
  solve();
	return 0;
}