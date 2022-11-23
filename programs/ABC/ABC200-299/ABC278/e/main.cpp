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
  ll H, W, N, h, w; 
  cin >> H >> W >> N >> h >> w;
  vector<vector<ll>> A(H);
  
  ll all[N + 5];
  ll area[N+5];
  set<ll> kind;
  rep(i,N+5){ 
    all[i]  = 0; 
    area[i] = 0; 
  }

  rep(i,H){
    vector<ll> AA(W+5);
    rep(j,W){
      cin >> AA[j];
      all[AA[j]] ++;
      if(h <= i || w <= j){
        area[AA[j]] ++;
        kind.insert(AA[j]);
      }
    }
    A[i]=move(AA);
  }
  rep(i,5) {
    vector<ll> AA(W+5);
    A.push_back(AA);
  }

  rep(i,H-h+1){
    ll firstArea[N+5];
    set<ll> firstKind = kind;
    rep(k,N+5) firstArea[k] = area[k]; 


    rep(j,W-w+1) {
      if(j == 0) {
        cout << kind.size() << " ";
        continue;
      }

      reps(k,i,i+h) {
        area[A[k][j-1]]++;
        area[A[k][j+w-1]]--;
        kind.insert(A[k][j-1]);
        if(area[A[k][j+w-1]] == 0) kind.erase(A[k][j+w-1]);
      }
      cout << kind.size() << " "; 
    }

    rep(k,N+5) area[k] = firstArea[k]; 
    kind = move(firstKind);

    rep(k,w) {
      area[A[i][k]]++;
      area[A[i+h][k]]--;
      kind.insert(A[i][k]);
      if(area[A[i+h][k]] == 0) kind.erase(A[i+h][k]);
    }
    cout << endl;
  }





}


int main()
{
  solve();
	return 0;
}