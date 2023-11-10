#include <bits/stdc++.h> 
#include <atcoder/all>

using namespace atcoder;
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
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


ll dx[8] = { 1, 1, 1 , 0,  0, -1,-1, -1};
ll dy[8] = { 0, 1, -1, 1, -1,  0, 1, -1};
void dfs(ll i, ll j, vector<string>& s) {
	
	rep(k,8) if(s[i+dx[k]][j+dy[k]] == '#') {
		s[i+dx[k]][j+dy[k]] = '.';
		dfs(i+dx[k], j+dy[k], s);
	}	
}

int main()
{
	ll h,w;cin >> h >> w;
	vector<string> s(h+2);rep(i,h){
		string S;
		cin >> S;
		s[i+1] = "." + S + ".";
	}

	string t = ""; rep(i,w+2)t += ".";
	s[0] = t; s[h+1] = t;


	ll ans = 0;
	reps(i,1,1+h)reps(j,1,1+w) if(s[i][j] == '#') {
		ans ++;
		s[i][j] = '.';
		dfs(i,j, s);
	}
	out(ans)

	return 0;
}