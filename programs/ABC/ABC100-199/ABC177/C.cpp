#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>

using namespace std;

#define debug false

#define rep(i,n)     for(int i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(int i = m; i < n; i++ ) 

typedef long long ll;
#define MOD 1000000000+7

	
int main(){
	ll N;cin >> N;
	vector<ll> A(N); rep(i,N) cin>> A[i];
	
	ll sum =0;rep(i,N) {sum+=A[i]; sum%=MOD;}
	ll ans = 0;
	rep(i,N-1) {
		sum += -A[i]+ MOD;
		sum %= MOD;
		ans +=A[i]*sum;
		ans %= MOD;
	}
	
	
	cout << ans;
	
    return 0;
}
