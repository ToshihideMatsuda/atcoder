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
vector<ll> G[MAX_N];
bool ck[MAX_N]; void clear() { rep(i,MAX_N) ck[i] = false; }
void readG(ll M) { rep(i,M) { ll a, b; cin >> a >> b; G[a].push_back(b); G[b].push_back(a);} }


int main()
{
	ll c[3][3];
	rep(i,3) rep(j,3) cin >> c[i][j];

	vector<ll> p;
	rep(i,9) p.push_back(i);
	ll bunshi = 0;
	ll all = 1;
	reps(i,1,10) all *= i;
	do {
		vector<ll> k1[3],k2[3],k3,k4; 
		rep(i,9) {
			k1[p[i]/3].push_back(c[p[i]/3][p[i]%3]);
			k2[p[i]%3].push_back(c[p[i]/3][p[i]%3]);
			if(p[i]/3 == p[i]%3)     k3.push_back(c[p[i]/3][p[i]%3]);
			if(p[i]/3 == 2 - p[i]%3) k4.push_back(c[p[i]/3][p[i]%3]);
		}

		rep(i,3) {
			if(k1[i][0] == k1[i][1] && k1[i][0] !=  k1[i][2]) {
				bunshi++;
				goto next;
			}

			if(k2[i][0] == k2[i][1] && k2[i][0] !=  k2[i][2]) {
				bunshi++;
				goto next;
			}
		}
		

			if(k3[0] == k3[1] && k3[0] !=  k3[2]) {
				bunshi++;
				goto next;
			}


			if(k4[0] == k4[1] && k4[0] !=  k4[2]) {
				bunshi++;
				goto next;
			}
		next:
			continue;
	} while(next_permutation(p.begin(),p.end()));

	double ans = (double)bunshi/(double)all;
	outd(1.0-ans)
	return 0;
}