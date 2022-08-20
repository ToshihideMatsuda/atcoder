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


void solve() {
  ll N; cin >> N;
  vector<ll> A;
  rep(i,N) {
    ll a = 0;
    cin >> a;
    A.push_back(a);
  }

  sort(A.begin(),A.end(),greater<ll>());
  vector<string> AA{to_string(A[0]), to_string(A[1]), to_string(A[2])};

  vector<ll> ans{
    stoll(AA[0] + AA[1] + AA[2]),
    stoll(AA[0] + AA[2] + AA[1]),
    stoll(AA[1] + AA[0] + AA[2]),
    stoll(AA[1] + AA[2] + AA[0]),
    stoll(AA[2] + AA[0] + AA[1]),
    stoll(AA[2] + AA[1] + AA[0])
  };


  sort(ans.begin(),ans.end(),greater<ll>());



  cout << ans[0] <<  endl;


}


int main()
{
  solve();
	return 0;
}