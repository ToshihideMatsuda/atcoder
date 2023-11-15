#include <bits/stdc++.h> 

using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) MIN(a,MIN(b,c))
#define out0(s) cout << s;
#define out(s)  cout << s << endl;
#define outd(s) cout << setprecision(15) << s << endl;
#define pb(s) push_back(s)
/*
	vector<ll> X = {4,7,3,1,7,9,4};
	SORT(X, <)
	OUT(X,",") //1,3,4,4,7,7,9,

	SORT(X, >)
	OUT(X," ") //9 7 7 4 4 3 1
*/
#define SORT(A,R) std::sort((A).begin(),(A).end(), [](auto const& x, auto const& y) { return x R y; });
#define OUT(A,separate) for(auto a : A) { cout << a << separate; }


#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N (2*100000+5)

ll mp[205][205];

ll gcd(ll a, ll b) {

	if(mp[a][b] != -1) return mp[a][b];
	if(mp[b][a] != -1) return mp[b][a];

	ll v = 0;
    if(b==0) v = a;
    else v = gcd(b, a%b);
	mp[a][b] = v;
	mp[b][a] = v;
	return v;
}

ll gcd0(ll a, ll b) {

    if(b==0) return a;
    else return gcd(b, a%b);
}

int main()
{
	rep(i,205) rep(j,205) mp[i][j] = -1;
	ll K; cin >> K;
	ll ans = 0;
	reps(a,1,1+K)reps(b,1,1+K)reps(c,1,1+K) {
		ans += gcd0(a,gcd0(b,c));
	}
	out(ans)
	return 0;
}