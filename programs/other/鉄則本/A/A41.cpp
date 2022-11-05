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

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N 300000 + 5


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
  auto Snum = runLengthEncoding(S);
  rep(i,Snum.size()) if(Snum[i].second >= 3) {
    cout << "Yes" << endl;
    return ;
  }
    cout << "No" << endl;

}


int main()
{
  solve();
	return 0;
}