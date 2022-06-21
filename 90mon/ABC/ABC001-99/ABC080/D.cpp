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

#define MAX_N 100000+5

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}


ll imos [31][MAX_N];


int main()
{
    ll N, C; cin >> N >> C;

    

    rep(_, N) {
        ll s, t, c; 
        cin >> s >> t >> c;
        imos[c][s] += 1;
        imos[c][t+1] += -1;
    }

     reps(c,1,31)rep(i,MAX_N - 1) {
        imos[c][i+1] = imos[c][i] + imos[c][i+1];
    }

    ll ans = 0;
    rep(i,MAX_N) { 
        ll tmp = 0;
        reps(c,1,31) if(imos[c][i] > 0){
            tmp += 1;
        }
        ans = max(ans, tmp);
    }

    cout << ans << endl;
    
	return 0;
}