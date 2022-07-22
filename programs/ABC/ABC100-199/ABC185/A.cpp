#include <iostream>
#include <vector>
#include <unordered_map>

typedef long long ll;
using namespace std;
ll dp[4][1000005];
#define MOD 998244353

int main(){
	ll a,b,c,d;
	cin >> a>> b>> c>> d;
	
	ll ans=min(a,min(b,min(c,d)));
	cout << ans <<endl;
    
    return 0;
}