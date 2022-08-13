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


void solve() {
	ll H1, W1; cin >> H1 >> W1;
	ll A[H1][W1];
	rep(i,H1)rep(j,W1) cin >> A[i][j];

	ll H2, W2; cin >> H2 >> W2;
	ll B[H2][W2];
	rep(i,H2)rep(j,W2) cin >> B[i][j];

	for(int h = 1; h  < 1 << H1; h ++) {
		vector<ll> hi;
		ll tmpH = h; 
		ll idx = 0;
		while(tmpH > 0) {
			if((tmpH & 1) == 1) {
				hi.push_back(idx);
			}
			tmpH = tmpH >> 1;
			idx ++;
		}

		if(hi.size() != H2) continue;


		for(int w = 1; w  < 1 << W1; w ++){
			vector<ll> wi;
			ll tmpW = w; 
			ll idx = 0;
			while(tmpW > 0) {
				if((tmpW & 1) == 1) {
					wi.push_back(idx);
				}
				tmpW = tmpW >> 1;
				idx ++;
			}

			if(wi.size() != W2) continue;

			rep(i,hi.size()) rep(j,wi.size()) {
				if(A[hi[i]][wi[j]] != B[i][j]) goto next;
			}

			cout << "Yes" << endl;
			return;

			next:
			continue;
		}
	}


	cout << "No" << endl;
	return;

}


int main()
{
  solve();
	return 0;
}