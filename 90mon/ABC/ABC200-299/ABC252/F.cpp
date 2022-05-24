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

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}


void solve(){
  ll N, L;
  cin >> N >> L;
  ll rem = L;
  priority_queue<ll, vector<ll>, greater<ll> > Q;
  rep(i,N) {
    ll a;
    cin >> a;
    Q.push(a);
    rem -= a; 
  }
  if(rem > 0)
  Q.push(rem);


  ll ans = 0;
  while(Q.size() > 1) {
    ll top1 = Q.top(); Q.pop();
    ll top2 = Q.top(); Q.pop();
    ans += top1 + top2;
    Q.push(top1 + top2);
  }

  cout << ans << endl;

}


int main()
{
  solve();
	return 0;
}

