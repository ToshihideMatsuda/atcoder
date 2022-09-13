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
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

vector<vector<ll>> v;

void dfs(vector<ll>& s, ll _l, ll N) {
  if(s.size() == N) {
    vector<ll> ss(s);
    v.push_back(ss);
    return;
  }

  if(_l < (N - s.size()) ) return;

  ll m = (_l + 1) - (N - s.size());
  reps(l, 1, m+1 ) {
    vector<ll> ss(s);
    ss.push_back(l);
    dfs(ss,_l - l, N);
  }

}



void solve() {
  ll N, M; cin >> N >> M;
  vector<string> S(N);
  set<string> T;
  rep(i,N) cin >> S[i];
  rep(i,M) {
    string t; 
    cin >> t;
    T.insert(t);
  }

  ll l = 0;
  rep(i,N) l += S[i].size();
  ll _l = 16 - l;
  vector<ll> s;
  dfs(s, _l, N-1);

  vector<ll> P;
  rep(i,N) P.push_back(i);

  do {
    for(auto vv :v) {
      string s;
      rep(i,N) {
        s += S[P[i]];
        if(i < N-1) {
          rep(_,vv[i]) 
            s += "_";
        }
      }
      //cout << s << endl;
      if(!T.count(s) && 3 <= s.size() &&  s.size() <= 16) {
        cout << s << endl;
        return;
      }
    }

  } while( next_permutation(P.begin(), P.end()));
  cout << -1 << endl;
  return;

}


int main()
{
  solve();
	return 0;
}