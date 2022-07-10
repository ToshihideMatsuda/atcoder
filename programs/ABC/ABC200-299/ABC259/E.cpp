#include <bits/stdc++.h> 
#include <unordered_map> 
using namespace std;

typedef long long ll;
bool debug = false;

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

ll getRandom(ll begin, ll end) {
    return begin >= end ? 0 : begin + (ll) ((end - begin)*(rand()/(double)RAND_MAX));
};

ll solve() {
    ll N; cin >> N;

    unordered_map<ll,ll> maxE;    // maxE[p]    = e -> 最大値eが複数
    unordered_map<ll,ll> maxcntE; // maxcntE[p] = c -> 最大値eの個数

    vector<ll> p[N], e[N];
    rep(i,N) {
        ll m; cin >> m;
        rep(j,m) {
            ll pp, ee; cin >> pp >> ee;
            maxE[pp] = max(maxE[pp] , ee);

            p[i].push_back(pp);
            e[i].push_back(ee);
        }
    }

    rep(i,N) rep(j, p[i].size()) {
        if(maxE[p[i][j]] == e[i][j]) {
            maxcntE[p[i][j]] ++ ;
        }
    }


    set<set<ll> > s;

    rep(i,N) {
        set<ll> ss;
        rep(j, p[i].size()) {
            ll emax = maxE[p[i][j]];
            ll emaxcntE = maxcntE[p[i][j]];
            
            if(emax == e[i][j] && emaxcntE == 1) {
                ss.insert(p[i][j]);
            }
        }
 
        s.insert(ss);
    }

    return s.size();


}


int main()
{
    
  cout << solve() << endl;
	return 0;
}