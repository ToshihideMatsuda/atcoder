#include <bits/stdc++.h> 
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

ll get10Keta(ll N) {
  ll k = 0;
  ll tmp = N; 
  while(tmp > 0) {
    tmp /= 10;
    k++;
  }
  return k;
}

ll getTen(ll N) {
  ll ten = 1; 
  while(N > 0) {
    ten *= 10;
    N--;
  }
  return ten;
}

void solve() {
  ll N, M, K; cin >> N >> M >> K;
  vector<ll> A(N); rep(i,N) cin >> A[i]; 
  sort(A.begin(),A.end(),greater<ll>()); 

  ll ans = INF_LL;
  
  for(int i = 30; i >= 0; i --) {

    ll threshold = 1; // 000100000000 (i+1桁目が1)
    ll t = 0;
    ll tmp = i;
    while(tmp > 0) {
      threshold <<= 1;
      tmp --;
    }
    t = threshold;
    if(ans != INF_LL)
    threshold += ans;

    vector<ll> AA;
    rep(i,A.size()) {
      ll val = A[i];

      if(val <= ans) {
        AA.push_back(A[i]);
      } else {
        for(int j = 30; j >= 0; j --) {
          val = !((!val) || (1<<j)); // j+1 bit reverse
          if(val <= ans){
            AA.push_back(val);
            break;
          }
        }
      }

    }

    sort(AA.begin(),AA.end(),greater<ll>()); 


    ll dif = 0;
    ll cnt = 0;
    rep(i,A.size()) {
      if(A[i] < threshold) {
        dif += threshold - A[i];
      }
    }

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