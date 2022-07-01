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
    ll H, W;
    cin >> H >> W;

    pair<ll,ll> p[2];
    int idx = 0;

    rep(i,H)
    {
        string S;
        cin >> S;
        rep(j,W)if(S[j] == 'o') {
            p[idx] = {i,j};
            idx ++;
        }
    }

    ll ans = abs(p[0].first - p[1].first) + abs(p[0].second - p[1].second);
    cout << ans << endl;

}


int main()
{
  solve();
	return 0;
}