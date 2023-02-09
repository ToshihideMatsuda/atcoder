#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) MIN(a,MIN(b,c))
#define out(s) cout << s << endl;
#define out2(s) cout << s;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N (2*100000+5)
void solve(){
    ll T;cin>>T;
    rep(_,T) {
      ll N ; cin >> N;
      vector<ll> A(N),  B(N);
      rep(i,N) cin >> A[i];
      rep(i,N) cin >> B[i];
      
      ll  b = 0;
      while(B[b%N] == B[(b+1)%N]){
        if(b == 0+N) break;
        b++;
      }

      if(b == N) {
        // Bは全て同じ文字
        bool ok = false;
        rep(i,N){
          if(B[0] == A[i]) {
            out("Yes");ok = true;
            break;
          }
        }
        if(ok) continue;
        

        out("No");
        continue;
      }
      

      ll a = -1;
      rep(i,N) {
        if(A[i] == B[b]) {
          a = i;
          bool ng = false;
          while(A[a%N] == A[(a+1) % N]) {
            if(a == i+N) {
              ng = true;
              break;
            }
            a++;
          }
          if(ng) {
            out("No")
            goto next;
          }
        }
      }

      if(a == -1) {
        out("No")
        goto next;
      }

      //aとbにて前に行って一致できるか検証
      rep(i,N) {
        if(A[(a-i+N)%N] == B[(b-i+N)%N]) continue; // ok
        if(A[(a-i+N+1)%N] == B[b-i]) {
          A[(a-i+N)%N] = A[(a-i+N+1)%N];
          continue; //ok
        }

        if(a == -1) {
          out("No")
          goto next;
        }
      }


      out("Yes");

      next:
      continue;
    }


    
    return;
}


int main()
{
  solve();
	return 0;
}