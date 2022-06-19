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

#define MAX_N 2*1000000+5

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}


void solve() {
    ll N, Q;

    cin >> N;

    vector<ll> a(N), b(N);
    vector<pair<ll,ll> > rA(N), rB(N);
    
    unordered_map<ll, ll> numMp;
    rep(i, N) cin >> a[i];
    rep(i, N) cin >> b[i];

    ll val = 0;
    
    rep(i, N) if( !numMp.count(a[i]) ) numMp[a[i]] = val++;
    rep(i, N) if( !numMp.count(b[i]) ) numMp[b[i]] = val++;

    set<ll> sA,sB;
    ll cntA, cntB = MINF_LL;
    rep(i,N) {
        sA.insert(a[i]);
        cntA = max(cntA, numMp[a[i]]);
        rA[i] = make_pair(sA.size() ,cntA);
    }

    rep(i,N) {
        sB.insert(b[i]);
        cntB = max(cntB, numMp[b[i]]);
        rB[i] = make_pair(sB.size() ,cntB);
    }


    cin >> Q;

    rep(i,Q) {
        ll x, y;
        cin >> x >> y;
        x--; y--;
        if( rA[x].first == rB[y].first && rA[x].second == rB[y].second ) cout << "Yes" << endl;
        else  cout << "No" << endl;
    }
}

int main()
{
    solve();
	return 0;
}