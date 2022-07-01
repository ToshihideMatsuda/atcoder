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


void solve() {
  ll N, M; cin >> N >> M;
  vector<ll> S(N-1),X(M);
  rep(i,N-1) cin >> S[i];
  rep(i,M) cin >> X[i];



  // A[0] = S[0] - ( S[1] - ( S[2] - A[3] ) )


  // B[0] = 0
  // B[1] = S[0]
  // B[2] = S[0] - S[1]
  // B[3] = S[0] - S[1] + S[2]
  // と構成すると
  // A[0] = B[i] + (-1)^i * A[i]
  vector<ll> B(N);
  B[0] = 0;
  reps(i, 1, N) {
    if(i % 2 == 1)  B[i] = B[i-1] + S[i-1];
    else            B[i] = B[i-1] - S[i-1];
  } 

  unordered_map<ll,ll> cnt;
  rep(m,M) {
      rep(i,N) {
        // A[0] = B[i] + (-1)^i * A[i] : A[i] = X[m]としたときのA[0]の値を集計
        ll val = 0;
        if(i % 2 == 0)  val = B[i] + X[m];
        else            val = B[i] - X[m];
        cnt[val] ++;
      }
  }

  ll ans = 0;
  for(auto e : cnt) ans = max(ans,e.second);
  cout << ans << endl;

}


int main()
{
  solve();
	return 0;
}