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




ll N;


int main()
{
  cin >> N;
  vector<ll> A(N); rep(i,N) cin >> A[i];

  ll taro = (N % 2 == 0);

  revs(i,N-1,0) {
    vector<ll> tmp;
    rep(j,i) {
      if(taro) {
        tmp.push_back(MAX(A[j],A[j+1]));
      } else {
        tmp.push_back(MIN(A[j],A[j+1]));
      }
    }
    taro = !taro;
    A = tmp;
  }

  cout << A[0] << endl;


}