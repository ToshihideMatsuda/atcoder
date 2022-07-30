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


bool solve(ll N, string &S) {
  if(N==2) return S[0] == S[1];
  return S[0] == 'B'|| S[N-1] == 'A';
}


int main()
{
  ll N; cin >> N;
  string S; cin >> S;

  bool ret = solve(N,S);
  
  if (ret) cout << "Yes";
  else cout << "No";
	return 0;
}