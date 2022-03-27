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
  int N;
  string T;
  cin >> N >> T;

  int x =0, y = 0;
  int d = 0;
  vector<int> dx = {1, 0, -1, 0};
  vector<int> dy = {0, -1, 0, 1};


  rep(i,N) {
      if(T[i] == 'S') {
          x +=dx[d];
          y +=dy[d];
      } else {
          d = (d + 1)%4;
      }
  }

  cout << x << " " << y << endl;

}



int main(){
    solve();
    return 0;
}

