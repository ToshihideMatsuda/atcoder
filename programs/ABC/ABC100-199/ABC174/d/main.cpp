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

vector<pair<string,ll> > runLengthEncoding(string S) {
    vector<pair<string,ll> > ret;
    ll i = 0;
    while(i < S.size()) {
        ll cnt = 1;
        while(i+1 < S.size() && S[i] == S[i+1]) {
            cnt++;
            i++;
        }
        ret.push_back(make_pair(S.substr(i,1),cnt));
        i++;
    }
    return ret;
}

void solve() {
  ll N; cin >> N;
  string S; cin >> S;
  ll cntR = 0; rep(i,N) if(S[i] == 'R') cntR ++;
  auto list = runLengthEncoding(S);

  ll ans = 0;
  
  for(auto e : list) {
    string s; ll c;
    tie(s, c) = e;

    if(s == "R") {
      cntR -= c;
    } else { // W
      if(c < cntR) {
        ans += c;
        cntR -= c;
      } else {
        ans += cntR;
        break;
      }
    }

    if(cntR <= 0)
      break;


  }
  cout << ans << endl;

}


int main()
{
  solve();
	return 0;
}