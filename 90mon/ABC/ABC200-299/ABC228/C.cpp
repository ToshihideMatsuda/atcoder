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

int main()
{
    ll N, K;
    cin >> N >> K;
    
    vector<ll> P(N), sP(N);
    rep(i,N){
        ll p1, p2, p3;
        cin >> p1 >> p2 >> p3;
        P[i] = p1+p2+p3;
        sP[i] = p1+p2+p3;
    }

    sort(sP.begin(), sP.end());

    rep(i,N) {
        auto l = upper_bound(sP.begin(),sP.end(),P[i]+300);
        ll rank = distance(l, sP.end()) + 1;
        if(rank <= K) {
            cout << "Yes" << endl;
        }
        else 
        {
            cout << "No" << endl;
        }
    }




	return 0;
}