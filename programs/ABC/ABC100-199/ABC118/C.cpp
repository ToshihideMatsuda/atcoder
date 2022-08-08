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
#define mp(a,b) make_pair(a,b)

#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5

ll gcd(ll a, ll b) {
    if(b==0) return a;
    return gcd(b, a%b);
}

void solve(){
    ll N; cin >> N;
    ll a; cin >> a;
    ll g = a;
    rep(i,N-1) {
        ll b; cin >> b;
        g = gcd(g, b);
    }

    cout << g << endl;

}

int main(){
    solve();

    return 0;
}
