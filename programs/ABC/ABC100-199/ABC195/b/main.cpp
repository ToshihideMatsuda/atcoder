#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) max(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) min(a,MIN(b,c))

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

void solve() {
  ll A, B, W; cin >> A >> B >> W;
  W *= 1000;

  ll small = INF_LL;
  ll large = 0;
  reps(cnt,1,W+1) {

    double w = (W * 1.0) / (cnt*1.0);
    if(A<= w && w <= B) {
      small = min(small,cnt) ;
      large = max(large,cnt) ;
    }
  }

  if(small < INF_LL) {
    cout << small << " " << large << endl;
  } else {
    cout << "UNSATISFIABLE" << endl;
  }

}


int main()
{
  solve();
	return 0;
}