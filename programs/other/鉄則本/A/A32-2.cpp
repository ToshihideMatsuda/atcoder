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


//先手が勝つ時にtrue
bool dp[100000 + 5];

void solve() {
  ll N, A, B; cin >> N >> A >> B; 


  rep(i,N+1) {
    if( (0 <= i-A && dp[i-A] == false) ||     //石をA個もしくはB個とって、相手を負け状態にできるなら、勝ち状態に設定
        (0 <= i-B && dp[i-B] == false)) dp[i] = true;
    else dp[i] = false; // 上記ができないなら負け状態に設定
  }

  if(dp[N]) cout << "First" << endl;
  else cout << "Second" << endl;

}


int main()
{
  solve();
	return 0;
}