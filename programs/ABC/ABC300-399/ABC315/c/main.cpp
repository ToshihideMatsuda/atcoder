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
	
	ll n;cin>>n;
	vector<ll>F2S[n+1];
	rep(i,n){
		ll f,s;
		cin>>f>>s;
		F2S[f].push_back(s);
	}
	
	rep(i,n+1){
		sort(F2S[i].begin(),F2S[i].end());
	}
	
	
	ll max =0;
	vector<ll> dif;
	
	rep(i,n+1)if(F2S[i].size()>0){
		dif.push_back(F2S[i].back());
	}
	if(dif.size()>1){
	sort(dif.begin(),dif.end());
	max=dif[dif.size()-1]+dif[dif.size()-2];
		}
	
	rep(i,n+1)if(F2S[i].size()>1){
		ll tmp =F2S[i][F2S[i].size()-1]+F2S[i][F2S[i].size()-2]/2;
		max=MAX(max,tmp);
	}
	cout<<max;
	return 0;
}
