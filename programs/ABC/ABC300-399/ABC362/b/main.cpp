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


#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int main() {
	vector<ll>a(2),b(2),c(2);
	cin>>a[0]>>a[1];
	cin>>b[0]>>b[1];
	cin>>c[0]>>c[1];
	vector<ll> r=
	{
		(a[0]-c[0])*(a[0]-c[0])+(a[1]-c[1])*(a[1]-c[1]),
		(a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]),
		(b[0]-c[0])*(b[0]-c[0])+(b[1]-c[1])*(b[1]-c[1]),
	};
	sort(r.begin(),r.end());
	if(r[0]+r[1]==r[2]){
		out("Yes")
	} else out("No")
  return 0;
}
