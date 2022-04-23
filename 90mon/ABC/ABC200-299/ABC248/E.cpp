#include <bits/stdc++.h> 

using namespace std;

#define debug false

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 



#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#if debug == true
    #define MAX_N 100 + 5
#else
    #define MAX_N 10000 + 5
#endif
//aとbの最大公約数を計算
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}
void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}
void UNSOLVABLE() {
  cout << "UNSOLVABLE" << endl;
}

void solve(){
    ll N, K; 
    cin >> N >> K;

    if(K == 1) {
        cout << "Infinity" << endl;
        return;
    }
    
    map<tuple<ll,ll, ll, int>,set<ll>> mp;

    vector<ll> X(N),Y(N);
    rep(i,N) cin >> X[i] >> Y[i];

    rep(i,N) reps(j,i+1,N) {
        if(X[i] == X[j]) {
            //cout << "(rx,ry,rb,f)=(" << X[i] << "," << "0,0,0)"<< endl;
            mp[{X[i],0, 0, 0}].insert(i);
            mp[{X[i],0, 0, 0}].insert(j);
        } else if(Y[i] == Y[j]) {
            //cout << "(rx,ry,rb,f)=(0,"  << Y[i] << ",0,1)"<< endl;
            mp[{0,Y[i], 0, 1}].insert(i);
            mp[{0,Y[i], 0, 1}].insert(j);
        } else {
            ll d = X[i] - X[j] > 0 ? 1 : -1;
            ll dx = d * (X[i] - X[j]);
            ll dy = d * (Y[i] - Y[j]);
            ll g = gcd(abs(dx),abs(dy));
            ll rx = dx/g;
            ll ry = dy/g;
            ll rb = Y[i] * rx - X[i] * ry;

            //cout << "(rx,ry,rb,f)=(" << rx << "," << ry << "," << rb << ",2)"<< endl;
            mp[{rx,ry, rb, 2}].insert(i);
            mp[{rx,ry, rb, 2}].insert(j);
        }
    }

    ll ans = 0;
    for(auto e: mp) {
        ll rx,ry,rb,f;
        tie(rx,ry,rb,f) = e.first;
        //cout << "mp(" << rx << "," << ry << ","  << rb << "," << f << "): size is " << e.second.size() << endl;
        if(e.second.size() >= K ) ans ++;
    }

    cout << ans << endl;


}



int main(){
    solve();
    return 0;
}

