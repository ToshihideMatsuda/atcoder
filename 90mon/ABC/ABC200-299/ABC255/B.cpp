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


void solve() {
    ll N, K;
    cin >> N >> K;
    
    bool ok[N];
    rep(i,N) ok[i] = false;

    rep(i,K) {
        ll a;
        cin >> a;
        a--;
        ok[a] = true;
    }
    
    vector<pair<ll,ll> > XY(N);
    rep(i,N) {
        ll x, y;
        cin >> x >> y;
        XY[i] = make_pair(x,y);
    }

    vector<double> dis(N);
    rep(i,N) {
        dis[i] = 100000 * 100000;
        rep(j,N) if(ok[j]) {
            double dx = abs(XY[i].first  - XY[j].first);
            double dy = abs(XY[i].second - XY[j].second);
            double d  = sqrt(dx*dx + dy*dy);
            dis[i] = min(dis[i], d);
        }
    }

    double ans = -1;
    rep(i,N) ans = max(ans,dis[i]);
    cout << setprecision(15) << ans << endl;


}


int main()
{
  solve();
	return 0;
}