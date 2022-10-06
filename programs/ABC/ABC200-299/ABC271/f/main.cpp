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
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N 2*100000+5
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

void solve() {
  ll N; cin >> N;
  ll A[N][N];
  rep(i,N)rep(j,N) cin >> A[i][j];

  map<ll,ll> S[N+5][N+5];
  bool checked[N+5][N+5];
  rep(i,N+5)rep(j,N+5) checked[i][j] = false;

  S[0][0][A[0][0]] = 1;
  S[N-1][N-1][A[N-1][N-1]] = 1;

  queue<tuple<ll,ll,ll,ll>> Q;
  Q.push({0,0,1,0});
  Q.push({N-1,N-1,-1,0});


  while(Q.size() > 0) {
    ll x, y, d, n;
    tie(x, y, d, n) = Q.front(); Q.pop();

    if(checked[x][y] == true) continue;
    if(d==1) if(n >= N-1)   continue;
    if(d==-1)if(n >= N-2) continue;
    for(auto s : S[x][y]) {
      ll key = s.first;
      ll num = s.second;
      S[x+d][y][key ^ A[x+d][y]] += num;
      S[x][y+d][key ^ A[x][y+d]] += num;
    }
    checked[x][y] = true;
    Q.push({x+d,y,d,n+1});
    Q.push({x,y+d,d,n+1});

/*
    cout << "----" << endl;
    rep(x,N) { 
      rep(y,N) {
      cout << "{";
      for(auto s : S[x][y])  {
          cout << s.first << "*" << s.second << ",";
      }
      cout << "}";
      cout << "\t";
    }
    cout << endl;
  }
  */
    
  }

  ll ans = 0;
  rep(x,N)rep(y,N)if(x+y == N-1){
    for(auto s : S[x][y]) {
      ll key = s.first;
      ll num = s.second;
      if(S[x+1][y].count(key)) ans += num * S[x+1][y][key];
      if(S[x][y+1].count(key)) ans += num * S[x][y+1][key];
    }
  }
  cout << ans << endl;
}


int main()
{
  solve();
	return 0;
}