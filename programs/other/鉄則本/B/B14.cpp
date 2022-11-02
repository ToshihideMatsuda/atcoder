#include <bits/stdc++.h> 
#include <unordered_map>
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

	set<ll> s[2];
	ll Ns[2] = {N/2, N-N/2};  
	rep(i,2) {
		ll  start = i * Ns[0];
		for(ll j = 0; j < (1 << Ns[i]); j++ ) {

			ll tmp = j;
			ll k = 0;
			ll sum = 0;
			while( tmp > 0 ) {
				if(tmp & 1 == 1) sum += A[k + start];
				tmp >>= 1;
				k++;
			}
			s[i].insert(sum);
		}
	}

	bool ok = false;
	for(auto s0 : s[0]){
		ll s1 = K - s0;
		if(s[1].count(s1)) ok = true;
	}

	cout << ( ok ? "Yes" : "No") << endl;



}

int main(){
    solve();
    return 0;
}

