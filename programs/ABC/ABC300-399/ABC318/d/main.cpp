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

ll n;
ll d[16][16];

ll ans = 0;

void dfs(ll v, vector<bool>& used) {

	ll p = -1;
	ll cnt = 0;
	rep(i,n) if(used[i] == false) {
		if(p == -1) p = i; 
		cnt ++;
	}

	if(cnt == 0 || cnt == 1) {
		ans = MAX(ans,v); 
		return;
	}

	used[p] = true;
	reps(i,p+1,n) if(used[i] == false){
		used[i] = true;
		dfs(v + d[p][i],used);
		used[i] = false;
	}

	if(cnt % 2 == 1) {
		ll q = -1;
		reps(i,p+1,n) if(used[i] == false) {
			q = i;
			break;
		}
		if(q > 0) {
			used[q] = true;
			reps(i,q+1,n) if(used[i] == false){
				used[i] = true;
				dfs(v + d[q][i],used);
				used[i] = false;
			}
			used[q] = false;
		}
	}

	used[p] = false;
}

int main()
{
	cin >> n;
	rep(i,n-1) reps(j,i+1,n) cin >> d[i][j];

	vector<bool> used(n,false);
	dfs(0,used);
	out(ans)
	
	return 0;
}