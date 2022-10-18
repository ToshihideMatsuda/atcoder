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

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
//#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) max(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) min(a,MIN(b,c))

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N 1505


const ll MAX = 10000000; 
bool initialized = false;
vector<ll> fac,finv,inv;
void init() {
    fac.resize(MAX);
    finv.resize(MAX);
    inv.resize(MAX);
    fac[0] = fac[1] = 1;
    inv[1] = 1;
    finv[0] = finv[1] = 1;
    for(int i=2; i<MAX; i++){
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = MOD-MOD/i*inv[MOD%i]%MOD;
        finv[i] = finv[i-1]*inv[i]%MOD;
    }
}
ll modComb(ll n, ll r){
    if (initialized == false) { 
      init();
      initialized = true;
    }
    if(n<r || n<0 || r<0) return 0;
    return fac[n]*finv[r]%MOD*finv[n-r]%MOD;
}
 

ll cnt[27];
string S;
ll dp[27][5005];
//dp[i][j]: j-length substring numbers using by alpha[i]s
//dp[i][j]=sum(k=0...min(j,cnt[i]))dp[i-1][j-k]*jCk

void solve() {
  cin>> S;
  rep(i,S.size())cnt[S[i]-'a'+1]++;
  
  ll l=0,ans=0;
  dp[0][0]=1;
  reps(i,1,27){
  	rep(j,l+cnt[i]+1){
  		ll tmp=0;
  		rep(k,min(j,cnt[i])+1){
  			tmp+=dp[i-1][j-k]*modComb(j, k);
  			tmp%=MOD;
  		}
  		dp[i][j]=tmp;
  	}
  	l+=cnt[i];
  }
  
  reps(j,1,S.size()+1){
  	ans+=dp[26][j];
  	ans%=MOD;
  }
  cout<<ans<<endl;
}


int main()
{
  solve();
	return 0;
}
