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
#define out(s) out1(s)
#define out1(s) cout << s << endl;
#define out2(s,t) cout << s << t << endl;
#define out3(s,t,r) cout << s << t << r << endl;
#define out4(s,t,r,u) cout << s << t << r << u << endl;
#define out5(s,t,r,u,o) cout << s << t << r << u << o << endl;
#define outd(s) cout << setprecision(15) << s << endl;
#define pb(s) push_back(s)

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353
#define INV2 499122177 // inverse of 2 in MOD

#define MAX_N (2*100000+5)
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }



int main()
{
	ll n,t,m;cin>>n>>t>>m;
	map<ll,set<ll>> dislike;
	rep(i,m){
		ll a,b;
		cin>>a>>b;
		dislike[a].insert(b);
		dislike[b].insert(a);
	}
	
	vector<ll> separate[n+1];
	for(int i=0;i<(1<<n);i++){
		ll cnt =0;
		set<ll> s;
		rep(j,n)if((i&(1<<j))>0){
			cnt++;
			for(auto dis : dislike[j+1]) if(s.count(dis)) {
				goto next;
			}
			s.insert(j+1);
		}
		separate[cnt].push_back(i);

		next:
		continue;
	}

	set<multiset<ll>> okPattern;

	for(int i=0;i<(1<<(n-1));i++){
		ll cnt =0;
		rep(j,n-1)if((i&(1<<j))>0)cnt++;
		if(cnt!=t-1)continue;
		multiset<ll> T;
		ll l=1;
		rep(j,n-1)if((i&(1<<j))>0){
			T.insert(l);
			l=1;
		}else{
			l++;
		}
		T.insert(l);
		okPattern.insert(T);
	}


	ll ans = 0;

	for(auto pattern : okPattern){
		
		set<ll> seed = {0};
		set<set<ll>> s = {seed};
		for(auto each: pattern) {
			set<set<ll>> nx;
			for(auto e: separate[each]) {
				for(auto i:s) {
					bool ok = true;
					for (auto j:i) {
						if( (j & e) != 0 ) {
							ok = false;
							break;
						}
					}
					if(ok) {
						i.insert(e);
						nx.insert(i);
					}
				}
			}
			if(nx.size()==0) goto end;
			s = nx;
		}
		end:

		for(auto i:s) {
			ll val = 0;
			for (auto j:i) {
				if( (val & j) != 0) {
					goto nn;
				}
				val |= j;
			}

			if(val == (1<<n) -1) {
				ans ++;
			}

			nn:
			continue;
		}


		
		continue;
	}
		
	
	out(ans)
	
	
	return 0;
}
