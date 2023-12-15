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

ll H, W; 
set<vector<vector<ll>>> S;
vector<vector<ll>>  B;

int main()
{
	cin >> H >> W;

	vector<vector<ll>> A = vector(H, vector<ll>(W,0));
	B = vector(H, vector<ll>(W,0));

	rep(i,H) rep(j,W) cin >> A[i][j];	
	rep(i,H) rep(j,W) cin >> B[i][j];

	queue<pair<vector<vector<ll>>,ll>> Q; 
	Q.push({A,0});

	ll ans = 0;

	while(Q.size() > 0) {
		auto [A, dps] = Q.front(); Q.pop();

		if(S.count(A)) continue;
		S.insert(A);
		bool eq = true;
		rep(i,H) rep(j,W) if(A[i][j] != B[i][j]) {
			eq = false;
			goto next;
		}
		next:

		if(eq) {
			out(dps);
			return 0;
		}

		rep(i,H-1) {
			vector A2 = A;
			rep(j,W) swap(A2[i][j], A2[i+1][j]);
			Q.push({A2, dps+1});
		}


		rep(j,W-1) {
			vector A2 = A;
			rep(i,H) swap(A2[i][j], A2[i][j+1]);
			Q.push({A2, dps+1});
		}

	}
	
	out(-1)
	
	return 0;
}
