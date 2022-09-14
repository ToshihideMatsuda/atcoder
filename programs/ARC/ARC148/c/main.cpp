#include <bits/stdc++.h> 
#include <unordered_map>
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) max(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) min(a,MIN(b,c))

#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


void solve() {
	ll N,Q; cin >> N >>Q;
	vector<ll>P(N+1);     // parent
	set<ll>C[N+1];        // child;
	P[1] = 0;
	reps(i,2,N+1){
		ll p; cin>> p;
		P[i] = p;
		C[p].insert(i);
	}

	bool S[N+1];  rep(i,N+1)S[i]=false;

	rep(i,Q){
		ll M; cin>>M;
		ll ans=0;
		vector<ll>vv;
		rep(j,M) {
			ll v;
			cin>> v;
			vv.push_back(v);
			S[v]=true;
		}

    unordered_map<ll,ll> mp;

    for(auto v : vv){
      mp[v] += C[v].size();
      mp[P[v]]--;
    }

		for(auto v : vv){
			if(!S[P[v]])ans++;
			ans+= mp[v];
		}

		for(auto v : vv) S[v]=false;
    
		cout << ans << endl;
	}
}
 
int main()
{
  solve();
	return 0;
}