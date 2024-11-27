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

#define MAX_N (4*100000+5)

// G[from]= {cost, to}

	ll h,w,k;
	vector<string> s;
	ll ans=0;

	void dfs(ll i, ll j, set<pair<ll,ll>>& ss){
		if(ss.size()==k+1){
			ans++;
			return;
		}
		
		if(0<i&&ss.count({i-1,j})==false&&s[i-1][j]=='.'){
			ss.insert({i-1,j});
			dfs(i-1,j,ss);
			ss.erase({i-1,j});
		}
		if(i<h-1&&ss.count({i+1,j})==false&&s[i+1][j]=='.'){
			ss.insert({i+1,j});
			dfs(i+1,j,ss);
			ss.erase({i+1,j});
		}
		
		if(0<j&&ss.count({i,j-1})==false&&s[i][j-1]=='.'){
			ss.insert({i,j-1});
			dfs(i,j-1,ss);
			ss.erase({i,j-1});
		}
		if(j<w-1&&ss.count({i,1+j})==false&&s[i][j+1]=='.'){
			ss.insert({i,j+1});
			dfs(i,j+1,ss);
			ss.erase({i,1+j});
		}
	}

int main()
{
 cin>> h >> w >> k;
 rep(i,h){
 	string t;cin>>t;
 	s.push_back(t);
 }
 rep(i,h)rep(j,w) if(s[i][j]=='.'){
 	set<pair<ll,ll>> ss;
 	ss.insert({i,j});
 	dfs(i,j,ss);
 }
 out(ans)
	
	return 0;
}
