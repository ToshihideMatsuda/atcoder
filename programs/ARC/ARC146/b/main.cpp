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
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) max(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) min(a,MIN(b,c))

#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5

void solve() {
  ll N, M, K; cin >> N >> M >> K;
  vector<ll> A(N); rep(i,N) cin >> A[i]; 
  sort(A.begin(),A.end(),greater<ll>()); 

  ll ans = 0;
  
  ll mask[32];// mask[i]=2^i
  rep(i,32) {
  	mask[i] = 1<<i;
  }
  
  
  
  for(int i = 30; i >= 0; i --) {

    ll threshold = 1; // 000100000000 (i+1桁目が1)
    ll tmp = i;
    while(tmp > 0) {
      threshold <<= 1;
      tmp --;
    }
    threshold += ans;
    vector<ll> sub;
    rep(i,A.size()) {
      ll val = A[i];
      bool mode=false;
      ll b =0;
      for(int j=31;j>=0;j--){
      	if(mode){
      		b += (threshold&mask[j]);
      	} else if((val&mask[j])>=1){
      		b += val&mask[j];
      	} else if((val&mask[j])==0&&(threshold&mask[j])>=1){
      		b += threshold&mask[j];
      		mode = true;
      	}
      }
      sub.push_back(b-A[i]);
    }

    sort(sub.begin(),sub.end()); 


    ll dif = 0;
    rep(i,K) dif += sub[i];

    if(dif <= M) {
      //ok
      ans = threshold;
    } 
  } 

  cout << ans << endl;


}


int main()
{
  solve();
	return 0;
}