#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i-- ) 
#define revs(i,m,n)  for(ll i = m; i > n; i++ ) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) max(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) min(a,MIN(b,c))

#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5


void solve(){
	ll N, K; cin >> N >> K;
	vector<ll> A(N);
	rep(i,N)cin >> A[i];
	ll l = 0, r = 0;
	ll sum = A[0];
	ll ans = 0;
	while(r < N) {
		if(sum <= K) {
			ans += r - l + 1;
			r++;
			sum += A[r];
		} else {
			sum -= A[l];
			l++;
		}
	}
	cout << ans << endl;




}

int main(){
    solve();
    return 0;
}

