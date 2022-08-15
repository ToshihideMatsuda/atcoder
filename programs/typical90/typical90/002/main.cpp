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

set<string> ans[21];
void dfs(ll n) {
  if(n <= 0) {
    return;
  }

  dfs(n-2);
  for(string s : ans[n-2]) {
    ans[n].insert("(" + s + ")");
  }


  for(int m = 2; n-m > 0 ; m += 2) {
    for(string s : ans[n-m]) {
      for(string t : ans[m])  {
        ans[n].insert(s+t);
      }
    }
  }
}

void solve() {
  ll N; cin >> N;
  if(N % 2 == 1) {
    cout << "" << endl;
    return;
  }
  ans[0] = { "" };
  dfs(N);

  vector<string> out;
  for(string s : ans[N]) out.push_back(s);
  sort(out.begin(), out.end()) ;
  for(string s : out) cout << s << endl;
}


int main()
{
  solve();
	return 0;
}