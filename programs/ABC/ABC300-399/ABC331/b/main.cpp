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
	ll s,m,l,n;cin>>n>>s>>m>>l;
	ll cost=INF_LL;
	for(int S=0;S<n+6;S+=6){
		for(int M=0;M+S<n+8;M+=8){
			ll L = 0;
			while(L<n-M-S)L+=12;
			
			
			
			
			cost=MIN((S/6)*s+(M/8)*m+(L/12)*l,cost);
			
		}
	}
	out(cost);
	return 0;
}
