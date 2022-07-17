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
	ll N;cin>> N;
	ll a[N]; rep(i,N)cin>>a[i];
	ll check =1;
	rep(i,N)if(a[i]==check)check++;
	if(check==1)cout << -1 <<endl;
	else cout << N+1-check << endl;
}

int main(){
	solve();
    return 0;
}
