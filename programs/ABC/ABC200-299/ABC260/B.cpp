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
#define mkp(a,b) make_pair(a,b)

#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5


void solve() {
  ll N, X, Y ,Z; cin >> N >> X >> Y >> Z;
  vector<pair<ll,ll> > A(N), B(N), AB(N); 
  rep(i,N) {
    ll a;
    cin >> a;
    A[i] = mkp(a,-i);
    AB[i] = mkp(a,-i);
  }
  rep(i,N){
    ll b;
    cin >> b;
    B[i] = mkp(b,-i);
    AB[i].first += b;
  }


  sort(A.begin(), A.end(), std::greater<pair<ll,ll> >());
  sort(B.begin(), B.end(), std::greater<pair<ll,ll> >());
  sort(AB.begin(), AB.end(), std::greater<pair<ll,ll> >());


  vector<ll> ans;
  set<ll> s;
  rep(i,X) {
    ans.push_back(A[i].second);
    s.insert(A[i].second);
  }

  ll cnt = 0;
  rep(i,N) {
    if(cnt >= Y) break;
    if(!s.count(B[i].second)){
      ans.push_back(B[i].second);
      s.insert(B[i].second);
      cnt++;
    }
  }

  cnt = 0;
  rep(i,N) {
    if(cnt >= Z) break;
    if(!s.count(AB[i].second)){
      ans.push_back(AB[i].second);
      s.insert(AB[i].second);
      cnt++;
    }
  }

  rep(i,ans.size()) ans[i] = -ans[i] + 1;
  sort(ans.begin(), ans.end());
  rep(i,ans.size()) cout << ans[i] << endl;
}


int main()
{
  solve();
	return 0;
}