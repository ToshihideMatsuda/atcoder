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

//aとbの最大公約数を計算
ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

void solve() {
    ll N; cin >> N;
    vector<ll> A(N);
    rep(i,N) cin >> A[i];
    
    vector<ll> gcdF(N), gcdB(N);

    gcdF[0] = A[0];
    gcdB[0] = A[N-1];

    reps(i,1,N) {
        gcdF[i] = gcd(A[i], gcdF[i-1]);
        gcdB[i] = gcd(A[N-1-i], gcdB[i-1]);
    }
    ll ans = max(gcdF[N-2], gcdB[N-2]);
    reps(i,1,N-1) {
        ans = max(ans, gcd(gcdF[i-1], gcdB[N-3 - (i-1)]));
    }
    cout << ans;



}


int main()
{
  solve();
	return 0;
}