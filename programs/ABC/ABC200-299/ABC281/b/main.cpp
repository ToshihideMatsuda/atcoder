#include <bits/stdc++.h> 
#include <unordered_map>
#include <regex>
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

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

void solveReg() {
  string S; cin >> S;
  
  // 一文字の英大文字
  // 100000 以上 999999 以下の整数を 10 進表記して得られる長さ 6 の文字列
  // 一文字の英大文字
  // の繰り返しの正規表現
  regex re(R"(([A-Z][1-9][0-9]{5,5}[A-Z])+)");
  std::cmatch results;
  if (regex_match(S, re)) {
    cout << "Yes"<< endl;
  } else {
    cout << "No" << endl;
  }
}

void solve() {
  string S; cin >> S;
  
  // 一文字の英大文字
  // 100000 以上 999999 以下の整数を 10 進表記して得られる長さ 6 の文字列
  // 一文字の英大文字
  // の繰り返しの正規表現
  bool ok = true;
  if(S.size() % 8 != 0) {
    ok = false;
  } else {
  for(ll i = 0; i < S.size(); i += 8) {
    if(
      ('A' <= S[i] && S[i] <= 'Z') &&
      ('1' <= S[i+1] && S[i+1] <= '9') &&
      ('0' <= S[i+2] && S[i+2] <= '9') &&
      ('0' <= S[i+3] && S[i+3] <= '9') &&
      ('0' <= S[i+4] && S[i+4] <= '9') &&
      ('0' <= S[i+5] && S[i+5] <= '9') &&
      ('0' <= S[i+6] && S[i+6] <= '9') &&
      ('A' <= S[i+7] && S[i+7] <= 'Z') 
      ) {
        
    } else {
      ok = false;
    }
  }
  }

  cout << (ok ? "Yes" : "No") << endl;


}



int main()
{
  solve();
	return 0;
}