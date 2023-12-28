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
	ll n, k; cin >> n >> k;
	vector<ll> a(k);rep(i,k) {
		cin >> a[i];
	}

	sort(a.begin(),a.end());
	

	vector<ll> r(k+1,0), l(k+1,0);

	for(int i = 1; i < k; i++) {
		l[i] = l[i-1];
		r[i] = r[i-1];
		if(i % 2  == 1) {
			l[i] += a[i] - a[i-1];
		} else {
			r[i] += a[i] - a[i-1];
		}
	}

	if(k %2 == 0) {
		out(l[k-1]);
		return 0;
	}


	
	ll ans = INF_LL;

	rep(i,k) if(i % 2 ==0){
		/*
		i==0 => i=0
		i==1 => i=0
		i==2 => i=1,i=2
		i==3 => i=1,i=2
		i==4 => i=3,i=4
		*/
		ll tmp = l[MAX(0,i-1)] + r[k-1] - r[i];
		ans = MIN(ans,tmp);
	}

	out(ans)

	
	return 0;
}
