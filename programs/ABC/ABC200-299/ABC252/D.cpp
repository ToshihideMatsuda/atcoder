#include <bits/stdc++.h> 
#include <unordered_map> 
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

void solve(){
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i,N) cin >> A[i];
  vector<ll> cnt(MAX_N);

  rep(i,N) cnt[A[i]] ++;
  rep(i,MAX_N-1) cnt[i+1] += cnt[i]; 

  ll ans = 0;
  rep(j,N) {
    ans += cnt[A[j]-1]*(N - cnt[A[j]]);
  }
  cout << ans << endl;

}


int main()
{
  solve();
	return 0;
}