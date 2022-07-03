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
#define p(a,b) make_pair(a,b)


#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5

ll N;
string S; 
vector<pair<ll,ll> > W;


void solve() {
    cin >> N >> S;
    W.resize(N);
    rep(i,N) {
        ll w; cin >> w;
        W[i] = p(w, S[i]);
    }

    sort(W.begin(),W.end());

    ll cnt = 0;
    rep(i,N) if( S[i] == '1') cnt ++;

    ll idx = 0;
    ll ans = cnt;
    while(idx < N) {
        auto toChild = W[idx];
        while (toChild.first == W[idx].first) {
            if( W[idx].second == '0' ) cnt ++;
            else cnt -- ;
            idx ++;
        }
        ans = max(ans,cnt);
    }

    cout << ans << endl;
}


int main()
{
  solve();
	return 0;
}