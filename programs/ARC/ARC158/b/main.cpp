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
#define outd(s) cout << setprecision(15) << s << endl;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 59)
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N (2*100000+5)

double f(double x1, double x2, double x3 ) {
	return (x1 + x2 + x3) / (x1 * x2 * x3);
}
int main()
{
	ll N; cin >> N;
	vector<double> x(N);
	vector<pair<double,double>> ax(N);
	rep(i,N){
		double xx; 
		cin >> xx;
		ax[i] = {1.0/xx, xx};
		x[i] = xx;
	}
	sort(ax.begin(), ax.end());
	sort(x.begin(), x.end());
	
	ll neg = 0;
	rep(i,N) if(x[i] < 0) neg ++;
	ll pos = N-neg;

	double mi = 0, ma=0;
	if(neg == 0 || pos == 0) {
		//全て正 or 全て負
		double v1 = f(x[0],   x[1],  x[2]);
		double v2 = f(x[N-1], x[N-2], x[N-3]);
		mi = MIN(v1,v2);
		ma = MAX(v1,v2);
	} else {
		vector<double> vv;
		if(N==3) {
			vv = {ax[0].second, ax[1].second, 												ax[N-1].second};
		} else if(N == 4) {
			vv = {ax[0].second, ax[1].second, 								ax[N-2].second, ax[N-1].second};
		} else if(N == 5) {
			vv = {ax[0].second, ax[1].second, ax[2].second, 				ax[N-2].second, ax[N-1].second};
		} else {
			vv = {ax[0].second, ax[1].second, ax[2].second, ax[N-3].second, ax[N-2].second, ax[N-1].second};
		}

		vector<double> s;
		rep(i,vv.size())rep(j,vv.size())rep(k,vv.size()){
			if(i!=j && i != k && j !=k) {
				s.push_back(f(vv[i],vv[j],vv[k]));
			}
		}

		sort(s.begin(),s.end());

		mi = s[0];
		ma = s[s.size() -1];

	}

	outd(mi)
	outd(ma)

	return 0;
}
