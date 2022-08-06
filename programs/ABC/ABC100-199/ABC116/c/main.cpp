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
#define min(a,b) (a<b?a:b)

typedef long long ll;

#define INF 1 << 28
#define MOD 998244353
#define MAX_N 100000+5


void solve(){
	ll N;cin>>N;
	vector<ll> h(N+1);
	rep(i,N) cin>> h[i];
	h[N]=0;
	
	ll ans = 0;
	int i = 0;
	while(i<N){
		if(h[i]==0){
			i++;
			continue;
		}
			ans++;
			
			int j=i;
			while(h[j]>0){
				j++;
			}
			for(int k=i;k<j;k++){
				h[k]-=1;
			}
		
	}
	cout << ans <<endl;
}

int main(){
	solve();
    return 0;
}
