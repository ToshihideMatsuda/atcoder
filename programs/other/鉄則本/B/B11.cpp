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
	ll N; cin>>N;
	map<ll,ll> A;
	rep(i,N){
		ll a;
		cin>>a;
		A[a]++;
	}
	A[0]=1;
	A[INF_LL]=1;
	ll i=-1;
	for(auto idx =A.begin();idx!= A.end();++idx){
		ll tmp = (*idx).second;
		(*idx).second = i;
		i+=tmp;
	}
	
	
	ll q; cin>> q;
	rep(i,q){
		ll x;cin>>x;
		auto idx = A.lower_bound(x);
		cout << (*idx).second<<endl;
	}

}

int main(){
    solve();
    return 0;
}
