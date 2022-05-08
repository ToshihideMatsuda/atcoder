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

#define MAX_N 2*1000000+5

void YES() {
  cout << "Yes" << endl;
  exit(0);
}

void NO() {
  cout << "No" << endl;
  exit(0);
}

//N以下の数について、素因数の数をcに登録
int prime[MAX_N];

ll hsh(ll a) {
    return a * (a + 24135) + 34152;
}

void solve() {
    ll N, Q;

    cin >> N;

    vector<ll> a(N), b(N), hA(N), hB(N);
    rep(i, N) cin >> a[i];
    rep(i, N) cin >> b[i];

    set<ll> Sa, Sb;

    rep(i, N) {
        if(Sa.count(a[i])) {
            hA[i] = hA[i-1];
        } else {
            Sa.insert(a[i]);
            hA[i] = hsh(a[i])  + ((i == 0) ? 0 : hA[i-1]);
        }

        if(Sb.count(b[i])) {
            hB[i] = hB[i-1];
        } else {
            Sb.insert(b[i]);
            hB[i] = hsh(b[i])  + ((i == 0) ? 0 : hB[i-1]);
        }
    }



    cin >> Q;

    rep(i,Q) {
        ll x, y;
        cin >> x >> y;
        if(hA[x - 1] == hB[y -1]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }


}

int main()
{
    solve();
	return 0;
}