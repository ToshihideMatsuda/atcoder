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

bool mode = true;
ll N;
ll f(ll i) {
  if(mode) return i;
  else return N+1-i;
}

// W = 0, B = 1, R = 2
// もしくは
// W = 0, B = 2, R = 1
// とすると、変換では % 3 の値が変わらない


// WW -> W : 0 -> 0
// BB -> R : 2 -> 2 (4 -> 1)
// RR -> B : 4 -> 1 (2 -> 2)
// WB -> B : 1 -> 1 (2 -> 2)
// WR -> R : 2 -> 2 (1 -> 1)
// RB -> W : 3 -> 1

void solve() {
  ll N; char C; cin >> N >> C;
  string A; cin >> A;

  unordered_map<char,ll> cnt;
  ll ans = 0;

  rep(i,A.size()) {
    if(A[i] == 'R')      ans ++;
    else if(A[i] == 'B') ans += 2;
  }

  if(
    (ans % 3 == 0 &&  C == 'W') ||
    (ans % 3 == 1 &&  C == 'R') || 
    (ans % 3 == 2 &&  C == 'B') 
    ) {
    cout << "Yes" << endl;
    return;
  } 

  cout << "No" << endl;

}




int main()
{
  solve();
	return 0;
}