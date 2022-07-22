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
#define MOD 998244353

ll gcd(ll a,ll b){
	if(b==0) return a;
	else gcd(b,a%b);
}
	
int main(){
	ll N,M; cin >> N >>M;
	vector<ll> A(M+1);
	rep(i,M) cin >> A[i];
	A[M]=N+1;
	sort(A.begin(),A.end());
	
	vector<ll> R;
	if(A[0]-1 >0) R.push_back(A[0]-1);
	reps(i,1,M+1) if(A[i]-A[i-1]-1 >0) R.push_back(A[i]-A[i-1]-1);
	
	if(R.size()==0){
		cout << 0 << endl;
		return 0;
	} else if(R.size()==1){
		cout << 1 << endl;
		return 0;
	} else {
		ll k = R[0];
		reps(i,1,R.size()){
			k = min(k,R[i]);
		}
		ll ans=0;
		rep(i,R.size()){
			ans += (R[i]+k-1)/k;
		}
		cout << ans << endl;
	}
	
	
    return 0;
}
