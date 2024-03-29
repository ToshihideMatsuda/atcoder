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

	
int main(){
	ll N;cin>> N;
	vector<ll> A(N);
	rep(i,N)cin>>A[i];
	sort(A.begin(),A.end());
	ll ans=A[N-1];
	ll cnt=2;
	for(int i=N-2;i>-1;i--){
		if(cnt>=N)break;
		cnt++;ans+=A[i];
		if(cnt>=N)break;
		cnt++;ans+=A[i];
	}
	cout<<(ans);
    return 0;
}
