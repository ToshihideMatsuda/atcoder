#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
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

#define MAX_N (2*100000+5)

ll cnt[10][10];

void solve() {
  ll n;cin>>n;
  reps(i,1,n+1){
  	ll t=i%10;
  	ll h=i;
  	while(10<=h)h /= 10;
  	cnt[h][t]++;
  }
  ll ans=0;
  reps(i,1,n+1){
  	ll t=i%10;
  	ll h=i;
  	while(10<=h)h /= 10;
  	ans+=cnt[t][h];
  }
  cout<<ans;
}


int main()
{
  solve();
	return 0;
}
