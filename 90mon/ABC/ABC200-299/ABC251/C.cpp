#include <bits/stdc++.h> 
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

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}

void solve() {
  ll N ;

  cin >> N;

  vector<string> S(N);
  vector<ll> T(N);

  unordered_map<string,pair<ll,ll>> mp;

  rep(i,N) {
    cin >> S[i] >> T[i];
    if(!mp.count(S[i])) mp[S[i]] = make_pair(T[i],(i + 1));
  }

  pair<ll,ll> maxT = make_pair(-1,0); 
  for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
    auto v = itr -> second;
    if( v.first > maxT.first) {
      maxT = v;
    } else if(v.first ==  maxT.first) {
      if(v.second < maxT.second) {
        maxT = v;
      }
    }
  }

  cout << maxT.second << endl;

}


int main()
{
  solve();
	return 0;
}