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

using mint = modint998244353;

int main()
{
	ll N; cin >> N;
	list<ll> P;
	rep(i,N) {
		ll p;
		cin >> p;
		P.push_back(p);
	}
	
	vector<pair<ll,ll>> ij;

	ll i = 0;
	for(auto idx = P.begin(); idx != P.end(); ++idx) {
		i ++;
		if(i == N-1) break;
		
		ll min = INF_LL;
		auto minIdx = idx;
		auto minJ = 0;
		
		ll j = i-1;
		for(auto idx2 = idx; idx2 != P.end(); ++idx2) {
			auto q = *(idx2);
			j++;
			if(q<min) {
				min = q;
				minIdx = idx2;
				minJ = j;
			}
		}

		if(minIdx == idx) continue;

		ij.push_back({minJ,i});

		auto eraseIdx0 = minIdx;
		auto eraseIdx1 = ++minIdx;
		ll a0 = *(eraseIdx0);
		ll a1 = *(eraseIdx1);
		P.erase(eraseIdx0);
		P.erase(eraseIdx1);

		P.insert(idx,a0);
		P.insert(idx,a1);
		

	}

	auto rbegin = P.rbegin();
	auto last = *rbegin;
	auto last_1 = *(++rbegin);


	if(last_1 < last) {
		out("Yes")
		out(ij.size())
		rep(i,ij.size()){
			out0(ij[i].first)
			out0(" ")
			out(ij[i].second-1)
		}
	} else {
		out("No")
	}

	return 0;
}