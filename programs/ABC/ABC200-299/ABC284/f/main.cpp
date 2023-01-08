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
#define MAX3(a,b,c) max(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) min(a,MIN(b,c))
#define out(s) cout << s << endl;
#define out2(s) cout << s;

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


ll N; 

ull ramdomM(ull l, ull r) {
  //64bit メルセンヌ ツイスター
  random_device seed_gen;
  mt19937_64 engine(seed_gen());

  ull ret = 0;
  do {
    ret = engine() % r;
  } while(ret <  l);
  return ret;

}

ll rolling_hash(string const& T){
  
  ll K = 10;
  //基底
  ull B[K];
  rep(k,K) B[k] = ramdomM(1ULL << 63, -1);

  // powB[k][n] = B[k]^n
  ull powB[K][N+1];
  rep(k,K) {
    powB[k][0] = 1;
    rep(n,N) powB[k][n+1] = powB[k][n] * B[k];
  }

  // sとtの先頭m文字のハッシュ値sh,thを計算
  ll sh[K], th[K];
  rep(k,K) {
    th[k] = 0;
    rep(n,N) {
      //0から順次
      th[k] = th[k] * B[k] + T[n];
    }
  }
  rep(k,K) {
    sh[k] = 0;
    rep(n,N) {
      //0から順次
      sh[k] = sh[k] * B[k] + T[2*N - 1 - n];
    }
  }
  
  // ハッシュ値を更新
  rep(i,N+1){
    bool ok = true;
    rep(k,K) {
      if(sh[k] != th[k]) ok = false;
    }
    if(ok) return i;

    if(i == N) break;

    rep(k,K) {
      th[k] = th[k] * B[k] + T[N + i] - T[i] * powB[k][N];
      sh[k] = sh[k] + (T[i] * powB[k][i] ) - (T[N + i] * powB[k][i] ); 
    }
  }



  return -1;
}

string f(ll i,  string const& S) {
  string St = S;
  reverse(St.begin(),St.end());
  string T = S.substr(0,i) +  St + S.substr(i, N-i);
  return T;
}

void solve(){
  cin >> N;
  string T; cin >> T;
  ll i = rolling_hash(T);
  if(i == -1) {
    out(i)
  } else {
    string S = T.substr(0,i) + T.substr(N+i, N-i);
    out(S)
    out(i)
  }
}



int main()
{
  solve();
  
	return 0;
}