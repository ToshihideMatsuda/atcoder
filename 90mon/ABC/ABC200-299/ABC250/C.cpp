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

ll P[MAX_N];  // P[x]  : 値 x がP[x]番目
ll rP[MAX_N]; // rP[n] : n番目の値が rP[y]  

void solve() {
    ll N, Q;
    cin >> N >> Q;

    reps(i, 1, N+1) {
        P[i]  = i;
        rP[i] = i;
    }

    rep(q, Q) {
        ll x;
        cin >> x;
        ll pX = P[x]; // xが何番目にいるか。

        if(pX == N) { // N
            ll y = rP[pX - 1]; //次の値

            P[x]--;
            P[y]++;

            rP[pX - 1] = x;
            rP[pX] = y;
        }
        else 
        {
            ll y = rP[pX + 1]; //次の値

            P[x]++;
            P[y]--;

            rP[pX + 1] = x;
            rP[pX] = y;
        }
    }

    reps(i, 1, N+1) cout << rP[i] << " ";
    cout << endl;

}

int main()
{
    solve();
	return 0;
}