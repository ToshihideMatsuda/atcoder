#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) max(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) min(a,MIN(b,c))
#define out(s) cout << s << endl;
#define out2(s) cout << s;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N 300 + 5


 // グラフの隣接行列
 // 配列d[a][b]には頂点a,b間の辺のコストを入れておき、a=bの時は0を、a,b間の辺が存在しないときはINFを入れておく。
 //
 // rep(i,MAX_N) rep(j,MAX_N) d[i][j] = (i == j ? 0 : INF);
 // rep(i,M){
 //   ll a, b, c;
 //   cin >> a >> b >> c;
 //   d[a][b] = c;
 //   d[b][a] = c;
 // }

pair<ll,ll> d[MAX_N][MAX_N];

ll N; 
void warshall_floyd() {
  reps(k,1,N+1) {           // 経由する頂点
      reps(i,1,N+1) {       // 始点
          reps (j,1,N+1) {  // 終点
              d[i][j] = min(d[i][j],
                {
                  d[i][k].first + d[k][j].first, 
                  d[i][k].second + d[k][j].second
                });
          }
      }
    }
}

void solve() {
  cin >> N;
  vector<ll> A(N+1);
  rep(i,N) cin >> A[i+1];
  vector<string> S(N);
  rep(i,N) cin >> S[i];

  rep(i,N+1) rep(j,N+1){ 
    if(i==j) {
      d[i][j] = {0,0}; 
    }else {
      d[i][j] =  {INF_LL, INF_LL};
    }
  }
  rep(i,N) {
    rep(j,S[i].size()) {
      if(S[i][j] == 'Y') {
        d[i+1][j+1] = {1, -1 * A[j+1]};
      }
    }
  }

/*
  rep(i,N+1) {rep(j,N+1){ 
    out2("{")
    if(d[i][j].first==INF_LL)out2("INF") else out2(d[i][j].first)
    out2(",")
    if(d[i][j].first==INF_LL)out2("INF") else out2(d[i][j].second)
    out2("} ")
  }
  out("")
  }
  */

  warshall_floyd();

/*
  rep(i,N+1) {rep(j,N+1){ 
    out2("{")
    if(d[i][j].first==INF_LL)out2("INF") else out2(d[i][j].first)
    out2(",")
    if(d[i][j].first==INF_LL)out2("INF") else out2(d[i][j].second)
    out2("} ")
  }
  out("")
  }
  */
  ll Q; cin >> Q;
  rep(i,Q) {
    ll u, v;
    cin >> u >> v;
    if(d[u][v].first == INF_LL) {
      out("Impossible")
    } else {
      out2(d[u][v].first)
      out2(" ")
      out(d[u][v].second * -1 + A[u])
    }
  }


}


int main()
{
  solve();
	return 0;
}