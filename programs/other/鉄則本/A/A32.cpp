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


unordered_map<ll,bool> mp;

ll N, A, B; 
ll rivalWin(ll n) {
  if(n < A) return true;
  if(mp.count(n)) return mp[n];
  
  bool iwin = false;
  if(0 <= n-A) iwin |= rivalWin(n-A);
  if(0 <= n-B) iwin |= rivalWin(n-B);

  mp[n] = !iwin;
  return !iwin;
}

void solve() {
  cin >> N >> A >> B; 

  //後手が勝つ時にtrue
  if(rivalWin(N)) cout << "Second" << endl;
  else cout << "First" << endl;


}


int main()
{
  solve();
	return 0;
}