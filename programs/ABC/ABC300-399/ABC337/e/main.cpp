#include <bits/stdc++.h> 
#include <atcoder/all>

using namespace atcoder;
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
#define OUT(A,separate) for(auto a : A) { cout << a << separate; }

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N (2*100000+5)



int main()
{
	ll N; cin >> N;
	ll b = 0;

	while( (1<<b)  < N) b++;
	out(b);

	rep(i,b) {
		vector<ll> v;
		reps(j,1,N+1) if( (j & (1 << i)) > 0 ) v.push_back(j);
		out0(v.size())
		out0(" ")
		OUT(v," ")
		cout << endl;
	}

	string S; cin >> S;
	
	ll ans = 0;

	rep(i,S.size()) ans += ((S[i] - '0') << i);
	if(ans == 0) ans = N;
	out(ans)

	
	return 0;
}
