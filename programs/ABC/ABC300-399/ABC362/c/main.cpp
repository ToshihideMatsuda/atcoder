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


int main()
{
	ll n;cin>>n;
	vector<ll> l(n),r(n);
	ll L=0,R=0;
	rep(i,n)cin>>l[i]>>r[i];
	rep(i,n){
		L+=	l[i];R+=r[i];
	}
	if(L<=0&&0<=R){
	} else {
		out("No")
		return 0;
	}

	out("Yes")
	vector<ll> ans(n);
	ll sum=0;
	rep(i,-1+n){
		L-=l[i];
		R-=r[i];
		if(L+l[i]<=0&&0<=R+l[i]){
			ans[i]=l[i];
		} else {
			ll lb=l[i],ub=r[i];
			while(ub-lb>1){
				ll mid=(lb+ub)/2;
				if(L+mid<=0&&0<=R+mid){
					ub=mid;
					break;
				} else if(R+mid<0){
					lb=mid;
				} else if(0<L+mid){
					ub=mid;
				}
			}
			ans[i]=ub;
		}
		//out0(L)out0(":")out0(R)out0("=")
		out0(ans[i]);
		
		sum+=ans[i];
		L+=ans[i];
		R+=ans[i];
		
		out0(" ")	
	}
	out(-sum);
	
	return 0;
}
