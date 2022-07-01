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

void solve(){
  ll A,B, C,D,E,F,X;
  cin >> A >> B >> C >> D >> E >> F >> X;

  ll Tk = X / (A+C);
  ll Ao = X / (D+F);
  
  ll resT = X - Tk * (A+C);
  ll resA = X - Ao * (D+F);

  ll ansT = Tk * (A*B);
  ll ansA = Ao * (D*E);

  if(resT < A) {
    ansT += resT*B; 
  } else {
    ansT += A*B;
  } 

  if(resA < D) {
    ansA += resA*E;
  } else {
    ansA += D*E;
  }

  if(ansT > ansA) {
    cout << "Takahashi" << endl;
  } else if(ansT == ansA) {
    cout << "Draw" << endl;
  } else {
    cout << "Aoki" << endl;
  }




}



int main(){
    solve();
    return 0;
}
