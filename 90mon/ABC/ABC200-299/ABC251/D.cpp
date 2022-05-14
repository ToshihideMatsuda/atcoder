#include <bits/stdc++.h> 
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
  ll W;
  cin >> W;


  vector<ll> ans;

  reps(i,1,100) ans.push_back(i);
  reps(i,1,100) ans.push_back(i*100);
  reps(i,1,100) ans.push_back(i*100*100);
  ans.push_back(100*100*100);

  cout << ans.size() << endl;;
  rep(i,ans.size()) cout << ans[i] << " ";
  cout << endl;
}


int main()
{
  solve();
	return 0;
}