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



void solve(){
	ll N; cin>>N;
	if(N%2==1)cout<<0<<endl;
	else{
		ll ans=0;
		ll mul=1;
		ll a =0;
		while(N>abs(mul)){
			mul*=5;
			a++;
			ans += (N/mul/2);
		}
		cout << ans << endl;
	}
}

int main(){
	solve();
    return 0;
}
