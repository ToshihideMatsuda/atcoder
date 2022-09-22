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

ll query(ll u , ll v) {
  cout << "? "<< u << " " <<  v << endl;
  ll r;
  cin >> r;
  return r;
}

void solve() {
  ll N; cin >> N;
  ll d[3][N];
  reps(i,3,N+1) {
    d[1][i] = 0;
    d[2][i] = 0;
  }

  unordered_map<ll,vector<ll>> idxs;
  ll m = INF_LL;
  reps(i,3,N+1) {
    d[1][i] = query(1,i);
    d[2][i] = query(2,i);
    if(d[1][i] == d[2][i]) if(d[1][i] + d[2][i] < m ) {
      m = d[1][i] + d[2][i];
    }
    
    if(abs(d[1][i] - d[2][i])) if(d[1][i] + d[2][i] < m ) {
      m = d[1][i] + d[2][i];
    }

    idxs[d[1][i] + d[2][i]].push_back(i);


  }

  if(m == 3) {
    if(idxs[3].size() != 2) { m = 1; } 
    else {
      // size == 2;
      if(query(idxs[3][0],idxs[3][1]) == 1 ) {
        m = 3;
      } else {
        m = 1;
      }
    }
  }

  cout << "! " << m << endl;



}


int main()
{
  solve();
	return 0;
}