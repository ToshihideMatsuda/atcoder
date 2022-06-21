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
    ll N; cin >> N;
    ll F[N][5][2];
    rep(i,N) rep(j,5) rep(k,2) cin >> F[i][j][k];
    ll P[N][11];
    rep(i,N) rep(j,11) cin >> P[i][j];

    ll ans = MINF_LL;
    reps(n, 1, 1 << 10){

        bool eigyo[5][2];
        rep(j,5)rep(k,2) eigyo[j][k] = false;
        
        ll nn = n;
        ll indx = 0;
        while(nn > 0) {
            if(nn & 1 == 1) eigyo[indx%5][indx/5] = true;
            indx ++;
            nn = nn >> 1;
        }

        ll c[N]; 
        rep(i,N) c[i] = 0;

        rep(i,N) rep(j,5) rep(k,2) {
            if(F[i][j][k] == 1 && eigyo[j][k]) {
                c[i] += 1;
            }
        }

        ll mouke = 0;

        rep(i,N) {
            mouke += P[i][c[i]];
        }


        if(ans < mouke) 
            ans = mouke;
    }
    cout << ans << endl;
}


int main()
{
  solve();
	return 0;
}