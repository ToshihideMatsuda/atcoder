#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define max(a,b)   (a>b?a:b)
#define max3(a,b,c) max(a,max(b,c))
#define min(a,b)   (a<b?a:b)
#define min3(a,b,c) min(a,min(b,c))


#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}

ll N;
string S;

void solve() {
  cin >> N >> S;

  ll cnt[N];
  rep(i,N) cnt[i] = 0;

  S = "*" + S + "*";
  rep(i,S.size()) {
      if(S[i] == 'R') {
          int x = 1;
          while(S[i-x] == 'A' && S[i+x] == 'C') x ++;
          cnt[x-1] ++;
      }
  }
  cnt[0] = 0;

  ll lb = 1, ub = N-1;

  ll ans = 0;
  

  while(lb <= ub) {

      //奇数回目の対応
      while(cnt[ub] == 0) {
          ub --;
          if(ub <= 0) goto end;
      }

      if(cnt[ub] > 0) {
          cnt[ub] --;
          cnt[ub-1]++;
          ans++;
      }

      //偶数回目の対応
      if(lb == ub) {
          lb = max(ub-1, 1);
      }

      while(cnt[lb] == 0) {
        lb++; 
        if(lb >= N) goto end;
      }

      if(cnt[lb] > 0) {
          cnt[lb] --;
          ans++;
      }
  }
end:

    cout << ans << endl;

}


int main()
{
  solve();
	return 0;
}