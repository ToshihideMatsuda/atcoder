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


void solve() {
  ll N; cin >> N;
  vector<tuple<ll,string,ll>> A;
  rep(i,N) {
    ll a = 0;
    cin >> a;
    A.push_back({a,to_string(a), 0});
  }

  sort(A.begin(),A.end(),greater<tuple<ll,string,ll>>());

  auto a0 = A[0], a1 = A[1], a2 = A[2];
  ll v,c = 0; string s;
  tie(v,s,c) = a0;

  ll l = s.length();


  tie(v,s,c) = a1;

  while(s.length() < l) {
    s += "0";
    c++;
  }
  a1 = {stoll(s), s, c};

  tie(v,s,c) = a2;
  while(s.length() < l) {
    s += "0";
    c++;
  }
  a2 = {stoll(s), s, c};

  vector<tuple<ll,string,ll>> AA {a0,a1,a2};


  sort(AA.begin(),AA.end(),greater<tuple<ll,string,ll>>());

  rep(i,3) {
    tie(v,s,c) = AA[i];

    while(c > 0) {
      v /= 10;
      c--;
    }
    cout << v;
  }

  cout << endl;


}


int main()
{
  solve();
	return 0;
}