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
    string S; cin >> S;
    ll ans = INF_LL;

    ll v = 0;

    rep(i,S.size()-2) {
        ll val = (S[i] - '0') * 100 +  (S[i+1] - '0') * 10 + (S[i+2] - '0');
        if(abs(753 - val) < ans) {
            ans = abs(753 - val);
        }
    }

    cout << ans << endl;
}


int main()
{
  solve();
	return 0;
}