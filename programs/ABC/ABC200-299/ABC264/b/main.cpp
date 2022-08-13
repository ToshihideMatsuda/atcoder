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

bool prime[MAX_N];
ll num[MAX_N];
void solve(){
	ll l,r;cin >>l >>r;
	l= abs(8-l);r=abs(8-r);
	if(max(l,r)%2==0) cout<<"white";
	else cout<<"black";
}

int main(){
	solve();
    return 0;
}