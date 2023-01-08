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

#define MAX_N (1000000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }

// powB[k][n] = B[k]^n (0<= n <= N)となる配列
ll powB[100][1000000+5];

struct RollingHash {
  
  private:
  //法M
  const ll M = 998244353;

  //基数
  vector<ll> B;

  //　基数のサイズ
  ll K;// = 0;

  // ローリングハッシュ値(※)を格納する配列
  // ※ hash[k] = S[0]*B[k]^(N-1) + S[1]*B[k]^(N-2) + ... + S[N-1] 
  vector<ll> hash;

  //文字列の長さ
  ll N;

public:
  RollingHash(string const& S) {
    
    N = S.size();
    if(B.size() == 0) {
      B = { 7013813588750972951LL, 8929143633738088283LL, 4837909145654321621LL, 6819033938186690237LL, 5107328697654825071LL};
//        6984644639313321301LL, 7981742035558655513LL, 5012529736381582537LL, 7764346403316436763LL, 8785404510772599077LL };

      K = B.size();
      rep(i,K) B[i] %= M;

      // powB[k][n] = B[k]^n (0<= n <=N)の計算
      rep(k,K) {
        powB[k][0] = 1;
        rep(n,N) powB[k][n+1] = (powB[k][n] * B[k]) % M ;
      }
    }

    //ハッシュ値の初期登録
    hash.resize(K);
    rep(k,K) {
      hash[k] = 0;
      rep(n,N) hash[k] = (hash[k] * B[k] + S[n]) % M;
    }
  }

  bool isSame(RollingHash other) {
    if(other.hash.size() == hash.size()) {
      rep(k,K) {
        if(other.hash[k] != hash[k]) return false;
      }
      return true;
    }
    return false;
  }

  // i番目(0-indexed)の文字bfがafに置き換わる場合のハッシュ値の計算
  //(af,bfは入力元が管理)
  void swap(ll i, char bf, char af) {
    rep(k,K) {
      hash[k] = (hash[k] + (af * powB[k][N-1-i]) - (bf * powB[k][N-1-i] )+ M * 100000000) % M;
    }
  }

  //末尾にafが加わり、先頭bfが除去された場合のハッシュ値の計算
  //(af,bfは入力元が管理)
  void push(char bf, char af) {
    rep(k,K) {
      hash[k] = (hash[k] * B[k] + af - bf * powB[k][N] + M * 100000000) % M;
    }
  }

};

void solve(){
  ll N;
  cin >> N;
  string T; cin >> T;

  string S  = T.substr(N,N);
  string St = T.substr(0,N);
  reverse(S.begin(),S.end());

  RollingHash SH(S), StH(St);


  rep(i,N+1) {
    bool same = SH.isSame(StH);
    if(i==N) break;
    if(same) {
      string S = T.substr(0,i) + T.substr(N+i, N-i);
      out(S)
      out(i);
      return;
    } else {
      SH.swap(N-1-i, T[N+i] , T[i]);
      StH.push(T[i], T[N+i]);
    }
  }
  out(-1);
  return;
}



int main()
{
  solve();
  
	return 0;
}