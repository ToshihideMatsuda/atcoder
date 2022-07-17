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

#define INF 1 << 28
#define MOD 998244353
#define MAX_N 100000+5


ll gcd(ll A,ll B){
	if(B==0)return A;
	return gcd(B,A%B);
}

void solve(){
	ll A,B;cin>>A>>B;
	ll g=gcd(A,B);
	ll ans=(A/g)*(B/g)*g;
	cout<< ans<<endl;
}

int main(){
	solve();
    return 0;
}
