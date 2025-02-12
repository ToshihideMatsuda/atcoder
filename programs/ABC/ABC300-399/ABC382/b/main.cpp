#include "bits/stdc++.h"
#include <iostream>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) MIN(a,MIN(b,c))
#define out(s) cout << s << endl;
#define out0(s) cout << s;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD (1000000000+7)

#define MAX_N (2*100000+5)

ll n,m;
vector<vector<ll>> ans;
void dfs(vector<ll>& v){
	
	if(v.size()==n+1){
		vector<ll> s;
		reps(i,1,n+1)s.push_back(v[i]);
		ans.push_back(s);
		return;
	}
	
	ll r = (n)-v.size();
	ll ten = r*10;
	
	int i =v.back()+10;
	for(;i+ten<=m;i++){
		v.push_back(i);
		dfs(v);
		v.pop_back();
	}
	
	
}


int main()
{
	cin>>n>>m;
	
	vector<ll> v;v.push_back(-9);

	dfs(v);
	
	out(ans.size())
	for(auto s:ans){
		for(auto t:s)cout<<t<<" "; 
		cout<<endl;
	}
	
	return 0;
}
