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
#define MOD 1000000007//998244353

#define MAX_N (2*100000+5)

long long modPow(long long x, long long a) {
  if (a == 0) return 1;
  if (a == 1) return x;
  if (a % 2) return (x * modPow(x, a - 1)) % MOD;
  long long t = modPow(x, a / 2);
  return (t * t) % MOD;
}

long long modInv(long long x) {
  return modPow(x, MOD - 2);
}

// 素因数分解の初期化関数
// f[n]= [ {p1,e1}, {p2,e2}, ..., {pm,em} ] : n = p1^e1 * p2^e2 * ... * pm^em
// f[n][p1] = e1, f[n][p2] = e2, ..., f[n][pm] = em
#define P 1000000
unordered_map<ll,ll> f[P+ 5];
void factorial_init(ll N) {
    f[1][1] = 1;
    for(ll i = 2; i < N+1; i++) {
        if(f[i].size() == 0) {
            for(int j = i; j < N+ 1; j+= i) {
                ll tmp = j;
                ll cnt = 0;
                while(tmp % i == 0) {
                    tmp = tmp / i;
                    cnt ++;
                }
                f[j][i] = cnt;
            }
        }
    }
}

void solve() {
  ll n;cin>> n;
  vector<ll>A(n);rep(i,n)cin>>A[i];
  factorial_init(P);
  
  unordered_map<ll,ll>all;
  
  
  rep(i,n){
  	for(auto a:f[A[i]]){
  		all[a.first]+=a.second;
  	}
  }
  
  
  unordered_map<ll,ll> g;
  rep(i,n){
  	for(auto a:f[A[i]]){
  		ll val = all[a.first] - a.second;
		if(g.count(a.first)) {
			g[a.first] = MIN(val, g[a.first]);
		} else {
			g[a.first] = val;
		}
  	}
   }
   
  ll G=1;
  for(auto a:g){
  	G*=modPow(a.first,a.second);
  	G%=MOD;
  }
  
  ll C=modInv(G);
  ll ans=0;

  for(auto a:all){
	C*=modPow(a.first,a.second);
	C%=MOD;
  }
  
  rep(i,n){
  	ll B=(C*modInv(A[i]))%MOD;
  
  	ans+=B;
  	ans%=MOD;
  }
  cout<<ans << endl;
  
}


int main()
{
  solve();
	return 0;
}
