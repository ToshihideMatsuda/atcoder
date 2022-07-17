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
	
	ll A,B; cin>>A >> B;
	bool a[3];
	rep(i,3)a[i]=true;
	a[A-1]=false;a[B-1]=false;
	rep(i,3)if(a[i]) cout << i+1<<endl;
}

int main(){
	solve();
    return 0;
}
