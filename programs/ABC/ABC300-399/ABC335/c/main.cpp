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
#define MOD 998244353

#define MAX_N (2*100000+5)


int main()
{
	ll Q,N;cin>>N>>Q;
	vector<pair<ll,ll>> D;
	for(ll i=N;i>0;i--){
		D.push_back({i,0});
	}
	
	while(Q-->0){
		ll t;cin>>t;
		if(t==1){
			char c;cin>>c;
			auto a = D[D.size()-1];
			pair<ll,ll> prev={a.first,a.second};
			if(c=='R')prev.first++;
			else if(c=='L')prev.first--;
			else if(c=='U')prev.second++;
			else prev.second--;
			D.push_back(prev);
		}else{
			ll p;cin>>p;
			auto[x,y]=D[D.size()-p];
			out0(x)out0(" ")out(y)
		}
	}
	
	return 0;
}
