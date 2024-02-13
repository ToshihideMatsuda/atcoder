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

ll gcd(ll a, ll b) {
    if(b == 0) return a;
    return gcd(b, a%b);
}

//拡張ユークリッドの互除法
//ax+by=gcd(a,b)を計算（正直理解しづらい。。。）
ll extgcd(ll a, ll b, ll& x, ll& y) {
    int d = a;
    if(b !=0) {
        
        d = extgcd(b, a%b, y, x);
        y -= (a/b) * x;    
    }
    else {
        //最終項
        x = 1;
        y = 0;
    }
    return d;
}

int main()
{
	
	ll X, Y; cin >>X >> Y;
	
	if(X == 0 || Y == 0) {
		reps(a,-2,3)reps(b,-2,3) {
			ll v2 = abs(b*X - a*Y);
			if(v2 == 2) {
				out0(a) out0(" ") out0(b)
				return 0;
			}
		}
		out(-1)
		return 0;
	}
	
	ll rX = X < 0 ? -1 :1;
	ll rY = Y < 0 ? -1 :1;
	
	ll x = rX * X;
	ll y = rY * Y;
	
	ll g = gcd(x,y);
	if(g > 2) {
		out(-1)
		return 0;
	}
	
	ll a,b;
    extgcd(x,y,a,b);
	
	if(g == 2) {
		a *= rY;
		b *= rX;
		b *= -1;
		out0(b) out0(" ") out0(a);
		return 0;
	} else if(g == 1) {
		//out("aaa")
		a *= rY;
		a *= 2;
		b *= rX;
		b *= 2;
		b *= -1;
		out0(b) out0(" ") out0(a);
		return 0;
	}
	
	
	
	return 0;
}
