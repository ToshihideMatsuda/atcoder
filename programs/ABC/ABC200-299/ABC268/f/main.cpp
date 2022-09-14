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

#define MAX_N 2*100000+5


void solve() {
  ll N; cin >> N;

  vector<tuple<string,ll,ll>> SXY;
  rep(i,N) { 
    string S;
    cin >> S;

    ll X = 0, Y = 0;

    rep(j,S.size()) {
      if(S[j] == 'X') X ++;
      if('0' <= S[j] && S[j] <= '9') Y += S[j] - '0';
    }
    SXY.push_back({S,X,Y});
  }
  
  sort(SXY.begin(), SXY.end(),[](tuple<string,ll,ll>  A, tuple<string,ll,ll>  B) {
    string _;
    ll XA, YA, XB, YB;
    tie(_,XA,YA) = A;
    tie(_,XB,YB) = B;
    return XB * YA < XA * YB ; 
  });

  ll ans  = 0;
  ll x = 0;
  rep(i,N) {
    string S = get<0>(SXY[i]);
    
    rep(j,S.size()) {
      if(S[j] == 'X') x ++;
      if('0' <= S[j] && S[j] <= '9') ans += (S[j] - '0') * x;
    }
  }
  cout << ans << endl;

}


int main()
{
  solve();
	return 0;
}