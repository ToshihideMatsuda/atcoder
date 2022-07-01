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
    ll N;cin>>N;
    vector<ll> A(N), AA(N); rep(i,N) {
        cin >> A[i];
        AA[i] = A[i];
    }

    sort(A.begin(),A.end());
    ll max1 = A[N-1], max2 = A[N-2];
    rep(i,N){
        ll ans  = AA[i] == max1 ? max2 : max1;
        cout <<  ans << endl;
    }

}


int main()
{
  solve();
	return 0;
}