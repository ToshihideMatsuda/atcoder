#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <stack>
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
#define out0(s) cout << s;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N (2*100000+5)


vector<pair<string,ll> > runLengthEncoding(string S) {
    vector<pair<string,ll> > ret;
    ll i = 0;
    while(i < S.size()) {
        ll cnt = 1;
        while(i+1 < S.size() && S[i] == S[i+1]) {
            cnt++;
            i++;
        }
        ret.push_back(make_pair(S.substr(i,1),cnt));
        i++;
    }
    return ret;
}

int main()
{	
	ll H, W; cin >> H >> W;
	ll K; cin >> K;

	vector<string> S(H+W);
	rep(i,H) cin >> S[i];
	rep(i,W) rep(j,H) S[i+H] += S[j][i];

	ll ans = INF_LL;
	set<string> target;
	rep(h,H+W) {

		if(S[h].size() < K) continue;

		string T = "";

		rep(i,S[h].size()) {
			if(S[h][i] == 'x'){
				if(T.length() >= K) {
					target.insert(T);
				}
				T = "";
			} else {
				T += S[h][i];
			}
		}
		if(T.length() >= K) {
			target.insert(T);
		}
	}

	for(auto T:target) {
		ll p = 0;
		rep(r,K-1)  if(T[r] == '.') p++;

		for(ll l = 0; l + K - 1 < T.size(); l++) {
			if(T[l + K - 1] == '.') p++;
			ans = MIN(ans, p);
			if(T[l] == '.') p--;
		}
	}


	if(ans==INF_LL) out(-1)
	else out(ans)

	return 0;
}
