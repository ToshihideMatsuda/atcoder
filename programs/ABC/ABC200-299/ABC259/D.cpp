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

#define MAX_N 3000+5

vector<ll> G[MAX_N];

void solve() {
    ll N; cin >> N;
    ll sx,sy,tx,ty;
    cin >> sx >> sy >> tx >> ty;
    vector<ll> x(N), y(N),r(N);
    rep(i,N){
        cin >> x[i] >> y[i] >> r[i];
    }

    double neg = 0.00000001;
    rep(i,N) rep(j,N) if(i < j){
        ll dx = x[i] - x[j];
        ll dy = y[i] - y[j];
        ll pr = r[i] + r[j];
        ll mr = r[i] - r[j];
        ll l2 = dx*dx + dy*dy;
        if(mr*mr <= l2 && l2 <= pr*pr) {
            G[i].push_back(j);
            G[j].push_back(i);
        }
    }

    ll s = -1, t =-1;
    rep(i,N) {
        ll d = ((x[i] - sx) * (x[i] - sx) + (y[i] - sy) * (y[i] - sy)) - r[i]*r[i];
        if(d == 0) {
            s = i;
        } 
        d = ((x[i] - tx) * (x[i] - tx) + (y[i] - ty) * (y[i] - ty)) - r[i]*r[i];
        if(d == 0) {
            t = i;
        } 
    }

    bool check[MAX_N];
    rep(i,N) check[i] = false;
    queue<ll> Q;
    Q.push(s);

    while(Q.size() > 0) {
        auto q = Q.front(); Q.pop();
        if(check[q] == false) {
            check[q] = true;
            for(auto g : G[q]) {
                Q.push(g);
            }
        }
    }
    
    if(check[t])
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;

}


int main()
{
  solve();
	return 0;
}