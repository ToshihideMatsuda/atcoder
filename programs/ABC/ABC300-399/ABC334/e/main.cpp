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

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N (2*100000+5)

using mint = modint998244353;

int main()
{
	
	ll h, w; cin >> h >> w;

	vector<string> S(h+2) ;
	
	rep(i,w+2) S[0] += ".";
	S[h+1] = S[0];

	vector M = vector (h+2,vector(w+2,-1));

	mint white = 0;
	rep(i,h) {
		string s; cin >> s;
		S[i+1] = "." + s + ".";

		rep(j,w) if(s[j] == '.') white ++;
	}

	ll dx[4] = {0,0,1,-1};
	ll dy[4] = {1,-1,0,0}; 

	ll mark = 0;
	reps(i,1,h+1)reps(j,1, w+1) {
		if(S[i][j] == '#' && M[i][j] == -1) {
			mark ++;
			queue<pair<ll,ll>> Q;
			Q.push({i,j});
			M[i][j] = mark;
			while(Q.size() > 0) {
				auto [p,q] = Q.front(); Q.pop();
				rep(k,4)if(S[p+dx[k]][q+dy[k]] == '#' && 
						   M[p+dx[k]][q+dy[k]] == -1) {
					M[p+dx[k]][q+dy[k]] = mark; 
					Q.push({p+dx[k], q+dy[k]});
				}
			}
		}
	}

	mint unionSize = mark;
	
	mint ans = 0;


	reps(i,1,h+1)reps(j,1, w+1) if(S[i][j] == '.') {
		set<ll> s;

		rep(k,4) if(S[i + dx[k]][j + dy[k]] == '#' && M[i + dx[k]][j + dy[k]] != -1) {
			s.insert(M[i + dx[k]][j + dy[k]]);
		}
		ans += (unionSize - s.size()+ 1) / white;

	}

	out(ans.val())

	
	
	return 0;
}
