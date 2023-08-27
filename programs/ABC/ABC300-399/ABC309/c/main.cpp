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
	ll H,W,K;cin>>H>>W>>K;
	
	vector<string> c(H);
	rep(i,H)cin>>c[i];
	ll ans=0;
	for(int h=0;h <(1<<H);h++){
		for(int w=0;w <(1<<W);w++){
			auto t=c;
			rep(i,H)if((h&(1<<i))>0){
				rep(j,W)t[i][j]='.';
			}
			
			rep(i,W)if((w&(1<<i))>0){
				rep(j,H)t[j][i]='.';
			}
			
			ll sum=0;
			rep(i,H)rep(j,W)if(t[i][j]=='#')sum++;
			if(sum==K) {
				//cout<<h<<","<<w<<endl;
				ans++;
			}
			
			
		}
	}
	
	cout<<(ans);
    return 0;
}
