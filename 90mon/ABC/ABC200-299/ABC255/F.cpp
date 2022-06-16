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

ll P[MAX_N], rP[MAX_N];
ll I[MAX_N], rI[MAX_N];
pair<ll,ll> ans[MAX_N];

void solve2(ll p, ll il, ll ir, ll pl,ll pr) {
    ll ip = rI[p];

    if(ip < il || ir < ip){
        cout << "-1" << endl;
        exit(0);
    }



    ll cntR = ir - ip;
    ll cntL = ip - il;

    ll posP = rP[p];

    
    if( pr - posP != cntL + cntR) {
        cout << "-1" << endl;
        exit(0);
    }
    

    ll l = cntL == 0 ? 0 : P[rP[p] + 1];
    ll r = cntR == 0 ? 0 : P[rP[p] + cntL + 1];
    ans[p] = {l, r};
    if(il < ip - 1) solve2(l, il, ip - 1, rP[p] + 1,      rP[p]+cntL);
    if(ip + 1 < ir) solve2(r, ip + 1, ir, rP[p]+cntL + 1, rP[p]+cntL+cntR);
}

void solve() {  
    // 6
    // 1 3 5 6 4 2, [1] [3 5] [6 4 2]
    // 3 5 1 4 6 2, [3 5] [1] [4 6 2]

    ll N; cin >> N;
    ll in;
    rep(i,N) {
        cin >> in;
        P[i] = in;
        rP[in] = i;
    }

    rep(i, N) {
        cin >> in;
        I[i] = in;
        rI[in] = i;
    }

    solve2(1, 0, N-1, 0, N-1);

    reps(i,1,N+1){
        cout << ans[i].first << " " << ans[i].second << endl;
    }

}


int main()
{
  solve();
	return 0;
}