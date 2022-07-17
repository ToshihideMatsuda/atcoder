#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define max(a,b)   (a>b?a:b)
#define max3(a,b,c) max(a,max(b,c))
#define min(a,b)   (a<b?a:b)
#define min3(a,b,c) min(a,min(b,c))
#define mkp(a,b) make_pair(a,b)

#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5


void solve() {
    string S;
    cin >> S;
    if(S[0] != S[1] && S[0] != S[2]){
        cout << S[0];
        return;
    } else if(S[0] == S[1]) {
        if(S[2] != S[0]) {cout << S[2];
        return;}
    } else if(S[0] == S[2]) {
        if(S[1] != S[0]) {cout << S[1];
        return;}
    }
    cout << "-1";
}


int main()
{
  solve();
	return 0;
}