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

//aとbの最大公約数を計算
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

//aとbの最小公倍数
ll lcm(ll a, ll b) {
    return a*b/gcd(a,b);
}


void solve() {
  ll A, B, C, D; cin >> A >> B >> C >> D;
  ll all = B - A + 1;

  ll divC = B/C - (A - 1)/C;
  ll divD = B/D - (A - 1)/D;
  ll lcmCD = lcm(C,D);
  ll divCD = B/lcmCD - (A - 1)/lcmCD;

  ll ans = all - divC - divD + divCD; 
  cout << ans << endl;

}


int main()
{
  solve();
	return 0;
}