#include <bits/stdc++.h> 


typedef long long ll;
using namespace std;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define rev(i,n)     for(ll i = n; i > -1; i--) 
#define revs(i,m,n)  for(ll i = m; i > n; i--) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) MAX(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)

int main()
{
	ll N; cin >> N;
	vector<ll> X(N), Y(N);
	vector<ll> xyOE[4];
	rep(i,N) {
		cin >> X[i] >> Y[i];
		if((X[i] + Y[i]) %2==0){
			xyOE[0].push_back(X[i] + Y[i]);
			xyOE[1].push_back(X[i] - Y[i]);
		} else {
			xyOE[2].push_back(X[i] + Y[i]);
			xyOE[3].push_back(X[i] - Y[i]);
		}
	}

	ll ans = 0;
	rep(i,4) {
		sort(xyOE[i].begin(), xyOE[i].end());
		ll n = xyOE[i].size();
		for(auto x: xyOE[i]) {
			ans += (((xyOE[i].size() - n) - (n - 1) )*x)/2;
			n--;
		}
	}

	cout << (ans) << endl;

	return 0;
}