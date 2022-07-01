#include <bits/stdc++.h> 

using namespace std;

#define debug false

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 



#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#if debug == true
    #define MAX_N 100 + 5
#else
    #define MAX_N 10000 + 5
#endif

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}
void UNSOLVABLE() {
  cout << "UNSOLVABLE" << endl;
}

vector<int> A;
int N;


void solve(){
  int N, K;
  cin >> N >> K;
  vector<int> A(N),B(N);
  rep(i,N) cin >> A[i];
  rep(i,N) cin >> B[i];

  int ng = 0;
  int aok = 1 << 1;
  int bok = 1;
  int s = aok + bok; //11: Ai=OK, Bi=OK, 10: Ai=OK Bi=NG, 01: Ai=NG,Bi=OK

  rep(i,N-1) {
    if(s == aok + bok) {
      s = ng;
      if(abs(A[i] - A[i+1]) <= K) { 
          s  += aok; 
      } else if(abs(B[i] - A[i+1]) <= K) {
          s  += aok; 
      }

      if(abs(A[i] - B[i+1]) <= K) { 
          s  += bok; 
      } else if(abs(B[i] - B[i+1]) <= K) {
          s  += bok; 
      }

    } else if(s == aok) {
      s = ng;
      if(abs(A[i] - A[i+1]) <= K) s  += aok; 
      if(abs(A[i] - B[i+1]) <= K) s  += bok; 
    } else if(s == bok) {
      s = ng;
      if(abs(B[i] - A[i+1]) <= K) s  += aok; 
      if(abs(B[i] - B[i+1]) <= K) s  += bok; 
    }

    if(s == ng) {
      NO();
    }
  }
  YES();
}



int main(){
    solve();
    return 0;
}

