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

void solve() {
    ll N, K, Q; cin >>N >> K >> Q;
    bool A[N];  rep(i,N) A[i] = false;
    rep(i,K) {
        ll a;
        cin >> a;
        a--;
        A[a] = true;
    }
    rep(_,Q) {
        ll L;
        cin >> L;
        ll tmp = 0;
        ll i = 0;
        while(tmp < L) if(A[i++]) tmp++;
        i = i-1;
        if(i == N-1) continue;
        if(A[i] == true && A[i+1] == false) {
            A[i] = false;
            A[i+1] = true;
        }
    }

    rep(i,N) {
        if(A[i]) cout << i+1 << " ";
    }



}


int main()
{
  solve();
	return 0;
}