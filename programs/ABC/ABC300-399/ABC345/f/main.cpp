#include <bits/stdc++.h> 
#include <atcoder/all>

using namespace atcoder;
using namespace std;
// 多倍長テンプレ（デバッグだとダメかも）

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

int main()
{
	ll N, M, K; cin >> N >> M >> K;

	set<pair<ll,ll>> G[N+1];

	rep(i,M) {
		ll u,v; cin >>u >> v;
		G[u].insert({v,i+1});
		G[v].insert({u,i+1});
	}


	if(K % 2 ==  1) {
		out("No")
		return 0;
	} else if(K == 0) {
		out("Yes")
		cout << endl;
		return 0;
	}

	vector<ll> ans;
	ll cnt = 0;
	vector<bool> lamp(N+1);
	reps(i,1,N+1) if(G[i].size() > 0){
		vector<pair<ll,ll>> era;
		for(auto [p,k] : G[i]) if(lamp[p]) era.push_back({p,k});
		for(auto [p,k] : era) {
			G[i].erase({p,k});
			G[p].erase({i,k});
		}
		
		bool full = ((G[i].size() + (lamp[i] ? 1 : 0 ) )% 2 == 1);
		bool first = true;
		for(auto [p,k] : G[i]) {

			G[p].erase({i,k});

			if(full == false && first) {
				first = false;
				continue;
			}

			first = false;
			ans.push_back(k);
			lamp[p] = !lamp[p];
			lamp[i] = !lamp[i];
			
			if(lamp[p] == true && lamp[i] == true) {
				cnt += 2;
				if(K == cnt) {
					out("Yes")
					out(ans.size())
					for(auto v : ans) {
						out0(v) out0(" ")
					}
					cout << endl;
					return 0;

				}
			}

		}
		
	}


	out("No")


	return 0;
}