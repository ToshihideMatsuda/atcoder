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

#define MAX_N 200+5

void solve() {
    ll N; cin >> N;
    vector<ll> x(N),y(N),P(N);
    rep(i,N) cin >> x[i] >> y[i] >> P[i];

    ll maxP = 0; 
    rep(i, N) maxP = max(P[i],maxP);
    ll lb = 0, ub = (INF_LL)/maxP;

    while(lb + 1 < ub) {
        ll mid = (lb + ub) / 2;
        vector<ll> G[MAX_N];

        rep(i,N)rep(j,N) 
            if(i != j) 
            if(abs(x[i] - x[j]) + abs(y[i] - y[j]) <= mid * P[i])  G[i].push_back(j);

        bool ok = true;
        rep(p,N) {
            bool check[N];
            rep(i,N) check[i] = false;

            queue<ll> Q;
            Q.push(p);
            while(Q.size() > 0) {
                auto q = Q.front();Q.pop();
                if(check[q]) continue;
                check[q] = true;
                for(auto p : G[q]) {
                    if(check[p]) continue;
                    Q.push(p);
                }
            }
            ok = true;
            rep(i,N) if(check[i] == false) ok = false;
            if(ok) break;
        }
        if(ok) {
            ub = mid;
        } else {
            lb = mid;
        }
    }

    cout << ub << endl;

}


int main()
{
  solve();
	return 0;
}