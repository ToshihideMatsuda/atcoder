#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define max(a,b)   (a>b?a:b)
#define max3(a,b,c) max(a,max(b,c))
#define min(a,b)   (a<b?a:b)
#define min3(a,b,c) min(a,min(b,c))


#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5


void solve() {
    double a, b, d;
    cin >> a >> b >> d;
    double s = d / 360.0 * M_PI * 2.0;
    //cout <<  M_PI * 2.0 << endl;
    double x = a * cos(s) - b * sin(s);
    double y = a * sin(s) + b * cos(s);
    cout << setprecision(15) << x << " " << y << endl;
}


int main()
{
  solve();
	return 0;
}