#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) max(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) min(a,MIN(b,c))

#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

void solve() {
  ll N; cin >> N;
  ll A = 1, B = N+1, C = 1, D = N+1, T;
  
  while(A + 1 < B ) {
    ll M = (A + B) / 2;
    cout << "? " << A << " " << (M - 1) << " 1 " << N << endl;
    cin >> T;
    if(T == -1) return;

    if(T < M-A) B = M;
    else A = M;
  }    


  while(C + 1 < D) {
    ll M = (C + D) / 2;
    cout << "? 1 " << N << " " << C << " " << (M - 1) << endl;
    cin >> T;
    if(T == -1) return;

    if(T < M-C) {
      D = M;
    } else {
      C = M;
    }
  } 

  cout << "! " << A << " " << C << endl;



  exit(-1);
}


int main()
{
  solve();
	return 0;
}