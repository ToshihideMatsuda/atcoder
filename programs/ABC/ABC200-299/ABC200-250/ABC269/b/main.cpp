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

void solve() {
  string S0 = "..........";
  vector<string> S(11);reps(i,1,11) cin >> S[i];

  ll A = 0, B = 0, C = 0, D = 0;
  reps(i,1,11) {
    if(S0 != S[i]) {
    if(A == 0) {
      A = i; B = i;
      rep(j,10) {
        if('#' == S[i][j]) {
          if(C == 0) {
            C = j+1;D = j+1;
          } else {
            D = j+1;
          } 
        }
      }
    } else {
      B = i;
    }
   }
  }

  cout << A << " "<< B  << endl;
  cout << C << " "<< D  << endl;

}


int main()
{
  solve();
	return 0;
}