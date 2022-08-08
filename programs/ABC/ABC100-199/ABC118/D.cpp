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

#define MAX_N 10000+5

ll gcd(ll a, ll b) {
    if(b==0) return a;
    return gcd(b, a%b);
}

// 1:2
// 2,5,5,4,5,6,3,7,6
// 1,2,3,4,5,6,7,8,9

vector<ll> dp[MAX_N];
ll cost[10] = { 0,2,5,5,4,5,6,3,7,6 };

vector<ll>& maxV(vector<ll>& v, vector<ll>& u) {
    ll vsum = 0, usum = 0;
    rep(i,10) {
        vsum += v[i];
        usum += u[i];
    }
    if(vsum > usum)       return v;
    else if (usum > vsum) return u;

    for(int i = 9; i > -1; i--) {
        if(v[i] > u[i]) return v;
        else if(u[i] > v[i]) return u;
    }

    // same
    return v;
}

void solve(){

    ll N, M; cin >> N >> M;

    vector<ll> A(M);
    rep(i,M) cin >> A[i];

    dp[0].assign(10,0);
    rep(i,N+1) {
        for(auto a : A) {
            if(i - cost[a] < 0) continue;
            if(dp[i - cost[a]].size() == 0) continue;
            
            vector<ll> tmp(dp[i - cost[a]]);
            tmp[a] ++;
            if(dp[i].size() == 0) dp[i] = tmp;
            else dp[i] = maxV(dp[i], tmp);
        }
    }

    
    for(int i = 9; i > -1; i--) {
        rep(_, dp[N][i]) {
            cout << i;
        }
    }
    cout << endl;

}

int main(){
    solve();

    return 0;
}
