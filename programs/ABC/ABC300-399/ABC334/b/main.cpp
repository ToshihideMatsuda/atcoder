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
	ll a, m, l, r; cin >> a >> m >> l >> r;

	if( a > 0) a %= m;
	else {
		a += (( INF_LL / m ) + 1 ) * m;
		a %= m;
	}

	if(l < 0) {
		ll add = ( ( -l / m )  + 1) * m; 

		l += add;
		r += add;
	}

	ll lcnt = 0, rcnt = 0;

	rcnt  = r / m;
	if(a <= r % m) {
		rcnt ++;
	}
	if(l >0){
		lcnt = (l-1) / m;
		if(a <= (l-1) %m) {
			lcnt ++;
		}
	}

	out(rcnt - lcnt)

	

	return 0;
}
