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
  ll N, K;
  cin >> N >> K;
  vector<string> S;
  rep(i,N) {
    string s;
    cin >> s;
    S.push_back(s);
  }

  ll ans = 0;
  for(int i = 1; i < (1 << N); i++) {
    set<string> s;
    int a[26];
    rep(i,26) a[i] = 0;

    int j = i;
    int indx = 0;
    while(j > 0) {
      if(j & 1 == 1) {
        s.insert(S[indx]);
      }
      indx++;
      j  = j >> 1;
    }

    for(string ss : s) {
      rep(l, ss.size()) {
        a[ss[l] - 'a']++;
      }
    }

    ll tmp = 0;

    rep(t,26) if(a[t] == K) tmp++;

    ans = max(ans, tmp);

  }

  cout << ans << endl;

}



int main(){
    solve();
    return 0;
}
