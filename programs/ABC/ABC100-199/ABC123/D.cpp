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
    ll X, Y , Z, K;
    cin >> X >> Y >> Z >> K;
    vector<ll> A(X), B(Y), C(Z);
    rep(i,X) cin >> A[i];
    rep(i,Y) cin >> B[i];
    rep(i,Z) cin >> C[i];


    vector<ll> AB;
    rep(i,X)rep(j,Y) AB.push_back(A[i] + B[j]);

    sort(AB.begin(), AB.end(), greater<ll>());
    sort(C.begin(), C.end(), greater<ll>());

    vector<ll> ABC;

    rep(i,min(X*Y,K))rep(k,Z) ABC.push_back(AB[i] + C[k]);


    sort(ABC.begin(), ABC.end(), greater<ll>());

    rep(i,K) cout << ABC[i] << endl;
    



}


int main()
{
  solve();
	return 0;
}