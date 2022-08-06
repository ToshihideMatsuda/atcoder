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
	ll a;cin>> a;
	set<ll> s;
	ll m=1;
	while(!s.count(a)){
		s.insert(a);
		if(a%2==0)a/=2;
		else a=3*a+1;
		m++;
	}
	cout << m << endl;
}

int main(){
	solve();
    return 0;
}
