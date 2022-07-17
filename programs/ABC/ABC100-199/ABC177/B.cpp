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
	string S, T;
	cin>>S >>T;
	
	ll ans=T.size();
	rep(i,S.size()){
		if(i+T.size()<=S.size()){
			ll cnt=0;
			rep(j,T.size()) if(S[i+j] != T[j]) cnt++;
			ans =min(ans,cnt);
		}
	}
	cout << ans;
	
    return 0;
}
