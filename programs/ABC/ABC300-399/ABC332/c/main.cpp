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
	ll N, M; cin >> N >> M;
	string S; cin >> S;

	S += '0';
	ll T = 0;
	ll t = 0; ll m = 0;
	for(int i = 0; i <N+1; i++) {
		if(S[i] == '0') {
			T = MAX(t, T);
			T += MAX(0, m - M - (T-t));
			t = 0; m = 0;
			continue;
		} else if(S[i] == '1') {
			m ++;
		} else {
			t ++;
		}
	}

	out(T)


	return 0;
}
