#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) MIN(a,MIN(b,c))
#define out(s) cout << s << endl;
#define out2(s) cout << s;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N (2*100000+5)

int main()
{

  ll N; cin >> N;
  ll ans = 0;
  vector<ll> v[N+1];
  ll tmp = 0;

  reps(i,1,1+N) {
    ll a;cin >> a;
    tmp += i/2;
    ans += tmp;

    v[a].push_back(MIN(i,N+1-i));
  }

  reps(i,1,1+N) {
    if(v[i].size() >= 2) {
      sort(v[i].begin(),v[i].end());
      rep(j,v[i].size() -1) {
        ans -= v[i][j] * (v[i].size() - 1 - j);
      }
    }
  }


  out (ans)
	return 0;
}