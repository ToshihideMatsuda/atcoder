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
#define MAX_N (2 * 100000 + 5)

void solve(){
    ll N;cin>>N;
    vector<ll> A;
    
    reps(s1,1,10)	
    //rep(s2,10)
    rep(s3,10)
    rep(s4,10)
    rep(s5,10)
    //rep(s6,10)
    rep(s7,10)
    rep(s8,10)
    //rep(s9,10)
    {	
    	N--;
    	if(N==0){
    	vector<ll> s = {s1,s1,s3,s4,s5,s5,s7,s8,s7};
    	rep(i,9) cout <<s[i];
    	return;
    	}
    }
    
    
    return;
}

int main(){

	solve();

    return 0;
}

