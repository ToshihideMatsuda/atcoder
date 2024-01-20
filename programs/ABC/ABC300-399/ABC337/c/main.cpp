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
	ll N; cin >> N;
	ll s = 0;
	vector<ll> G[N+1];
	reps(i,1,1+N) {
		ll a; cin >> a;
		if(a == -1) {
			s = i;
		} else {
			G[a].push_back(i);
		}
	}

	queue<ll> Q;
	Q.push(s);
	while(Q.size() > 0) {
		auto q = Q.front();Q.pop();
		out0(q) out0(" ")
		for(auto g:G[q])Q.push(g);
	}
	
	
	return 0;
}
