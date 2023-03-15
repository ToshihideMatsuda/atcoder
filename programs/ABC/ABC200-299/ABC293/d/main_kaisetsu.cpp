#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <unordered_map>
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
#define out2(s) cout << s;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 59)
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N (2*100000+5)

vector<ll> G[MAX_N];
bool ck[MAX_N];

int main()
{
	ll N, M; cin >> N >> M;
	rep(i,M) {
		ll A, C; char B, D;
		cin >> A >> B >> C >> D;

		G[A].push_back(C);
		G[C].push_back(A);
	}


	ll l = 0;
	ll nl = 0;

	reps(n,1,N+1) {
		if(ck[n] == true) continue;

		ck[n] = true;

		queue<ll> Q;
		Q.push(n);

		bool circle = true;

		while(Q.size() > 0) {
			ll q = Q.front(); Q.pop();
			if(G[q].size() != 2) {
				circle = false;
			}

			for(auto g : G[q]) if(ck[g] == false){
				ck[g] = true;
				Q.push(g);
			}
		}
		if(circle) {
			l ++;
		} else {
			nl++;
		}

	}

	out2(l)
	out2(" ")
	out(nl)

	return 0;
}
