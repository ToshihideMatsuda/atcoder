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

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

void solve() {
  ll H, M; cin >> H >> M;

  while(true) {
    string tH, tM;
    
    if(H < 10) {
      tH = "0";
    }else if(H < 20) {
      tH = "1";
    } else {
      tH = "2";
    }

    if(M < 10) {
      tH += "0";
    }else if(M < 20) {
      tH += "1";
    } else if(M < 30) {
      tH += "2";
    } else if(M < 40) {
      tH += "3";
    } else if(M < 50) {
      tH += "4";
    } else  {
      tH += "5";
    } 

    tM = to_string(H%10) + to_string(M%10);

    ll h = stoll(tH),m = stoll(tM);
    if(0 <= h && h <= 23 && 0<= m && m <= 59) {
      cout << H << " " << M ;
      break;
    }




    if(M < 60){ M++;}
    else {
      M = 0;
      if(H < 23) { H ++;} 
      else {
        H = 0;
      }
    }

  }



}


int main()
{
  solve();
	return 0;
}