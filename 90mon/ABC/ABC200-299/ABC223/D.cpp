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

#define MAX_N 2*1000000+5

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}

vector<ll> G[MAX_N];
ll from[MAX_N];

void solve() {
  ll N, M;
  cin >> N >> M;

  vector<ll> ans;

  rep(i,M) {
    ll a, b;
    cin >> a >> b;

    a--; b--;
   // a < b の半順序
    G[a].push_back(b);
    from[b]++;
  }

  // toの個数が0個のもの
  priority_queue<ll, vector<ll>, greater<ll>> zQ;
  
  rep(a,N) if(from[a] == 0) zQ.push(a);

  while(zQ.size() > 0) {
    ll a = zQ.top();zQ.pop();

    ans.push_back(a);
    for(ll b : G[a]) {
      from[b] --;

      if(from[b] == 0) {
        zQ.push(b);
      }
    }
  }

  if (ans.size() == N) {
    rep(i,N) {
      cout << (ans[i] + 1) << " ";
    }
  } else {
    cout << -1;
  }
  cout << endl;
}

int main()
{
    solve();
	return 0;
}