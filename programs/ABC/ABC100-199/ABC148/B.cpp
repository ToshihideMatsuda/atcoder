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
	ll N;cin>>N;
	string s,t;cin>>s>>t;
	rep(i,N)cout<<s[i]<<t[i];
	cout<<endl;
}

int main(){
	solve();
    return 0;
}
