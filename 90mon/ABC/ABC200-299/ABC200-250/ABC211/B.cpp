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

#define MAX_N 2*1000000+5

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}

//N以下の数について、素因数の数をcに登録
int prime[MAX_N];

void solve() {
  set<string> S;
  string ch[] = { "H" , "2B" , "3B" , "HR"};
  rep(i,4) {
      string s;
      cin >> s;
      S.insert(s);
  }
  rep(i,4)  if(! S.count(ch[i])) NO();
  YES();

}

int main()
{
    solve();
	return 0;
}