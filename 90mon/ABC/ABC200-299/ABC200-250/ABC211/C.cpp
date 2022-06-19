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
#define MOD 1000000000 + 7// 998244353

#define MAX_N 100000+5

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}

ll dp[9];

void solve() {
    string S;
    cin >> S;

    char CH[] = {'c' , 'h' , 'o' , 'k' , 'u' , 'd' , 'a' , 'i'};
    
    dp[0] = 1;

    rep(i,S.size()) {
        char ch = S[i];
        ll indx = -1;
        rep(j,8) {
            if(ch == CH[j]) {
                indx = j;
                break;
            }
        }


        if(indx != -1) {
            // not select
            dp[indx+1] += dp[indx];
            dp[indx+1] %= MOD;
        }
    }

    cout << dp[8] << endl;

}

int main()
{
    solve();
	return 0;
}