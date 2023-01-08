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
#define out(s) cout << s << endl;
#define out2(s) cout << s;

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

//N以下の数について、素因数の数をcに登録
vector<pair<ll,ll>> ps;

ll c[10000000LL+10000LL];
void elats(ll N){
	for(ll i= 2; i<N+1;i++){
		c[i]=0;
	}
	
	for(ll i= 2; i<N+1;i++){
		if(c[i]==0){
      ps.push_back({i,i*i});
			for(ll j=i;j<N+1;j +=i){
				c[j] +=1;
			}
		}
	}
}


void solve() {

  elats(10000000LL + 1000LL);

  ll T; cin >> T;
  rep(i,T) {
    ll N; cin >> N;
    for(auto p :ps) {
      if(N % p.second == 0){
        out2(p.first);
        out2(" ");
        out(N / p.second)
        break;
      } else if(N % p.first == 0) {
        ll pp = sqrt(N / p.first);
        out2(pp);
        out2(" ");
        out(p.first);
        break;

      }
    }
  }
}


int main()
{
  solve();
	return 0;
}