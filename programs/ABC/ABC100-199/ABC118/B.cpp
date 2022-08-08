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


void solve(){
    ll N, M; cin >> N >> M;
    ll cnt[M+1]; rep(i,M+1) cnt[i] = 0;
    ll ans = 0;
    rep(i,N) {
        ll k; cin >> k;
        rep(i,k) {
            ll x; cin >> x;
            cnt[x]++;
        }
    }

    rep(i,M+1) if(cnt[i] == N) ans++;
    cout << ans << endl;

}

int main(){
    solve();

    return 0;
}
