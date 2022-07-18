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
#define mkp(a,b) make_pair(a,b)

#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5


void solve() {
  ll N, M; cin >> N >> M;
  ll A[N], B[N];
  rep(i,N) {
    cin >> A[i] >> B[i];
    A[i] --; B[i] --;
  } 
  ll f[M+2];
  rep(i,M+2)f[i] = 0;
  ll l = 0, r = 0;
  while(l < M) {
    ll inf = INF_LL;
    ll lb = r-1, ub = M+1;
    while(ub - lb > 1) {
      bool ok = true;
      ll tmp = INF_LL;

      ll mid = (lb + ub) / 2;
      rep(i,N) {
        bool Aok = l <= A[i] && A[i] <= mid;
        bool Bok = l <= B[i] && B[i] <= mid;

        if(Aok & Bok) tmp = min(tmp,max(A[i],B[i]));
        else if(Aok) tmp = min(tmp, A[i]);
        else if(Bok) tmp = min(tmp, B[i]);

        if(!Aok && !Bok){ 
          ok = false;
          break;
        }
      }
      if(ok) {
        ub = mid;
        inf = tmp;
      } else {
        lb = mid;
      }
    }
    r = ub;
    if(r >= M) break;
    reps(i,l,inf+1) {
      f[r - i + 1] ++;
      f[M - i + 1] --;
    }
    l = inf+1;
  }

  rep(i,M) f[i+1] = f[i+1] + f[i]; 

  reps(i,1,M+1) cout << f[i] << " ";
  cout << endl;

}


void solve2() {
  ll N, M; cin >> N >> M;
  ll A[N], B[N];
  rep(i,N) {
    cin >> A[i] >> B[i];
    A[i] --; B[i] --;
  } 
  ll f[M+2];
  rep(i,M+2)f[i] = 0;
  ll l = 0, r = 0;
  while(l < M) {
    ll inf = INF_LL;
    while(r < M) {
      bool ok = true;
      inf = INF_LL;
      rep(i,N) {
        bool Aok = l <= A[i] && A[i] <= r;
        bool Bok = l <= B[i] && B[i] <= r;
 
        if(Aok & Bok) inf = min(inf,max(A[i],B[i]));
        else if(Aok) inf = min(inf, A[i]);
        else if(Bok) inf = min(inf, B[i]);
 
        if(!Aok && !Bok){ 
          ok = false;
          break;
        }
      }
      if(ok) break;
      r++;
    }
    if(r >= M) break;
    reps(i,l,inf+1) {
      f[r - i + 1] ++;
      f[M - i + 1] --;
    }
    l = inf+1;
  }
 
  rep(i,M) f[i+1] = f[i+1] + f[i]; 
 
  reps(i,1,M+1) cout << f[i] << " ";
  cout << endl;
 
}
int main()
{
  solve();
	return 0;
}