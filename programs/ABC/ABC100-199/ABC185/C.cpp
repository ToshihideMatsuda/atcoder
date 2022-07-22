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

ll dp[12][200];
	
int main(){
	ll L;cin>>L;
	
	reps(i,1,12){
		reps(j,1,L){
			if(i==1){
				dp[i][j]=1;
			} else {
				dp[i][j] += dp[i][j-1]+dp[i-1][j-1];
			}
		}
	}
	ll ans =0;
	reps(j,1,L+1){
		ans+= dp[11][j];
	}
	
	cout << ans << endl;
	
	
    return 0;
}
