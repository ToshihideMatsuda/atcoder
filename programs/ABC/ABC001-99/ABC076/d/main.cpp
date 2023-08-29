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
	ll N; cin >> N;
	vector<ll> t(N), v(N);
	ll time = 0;
	rep(i,N) {
		cin >> t[i];
		time +=  t[i];
	}
	t.push_back(1);
	time += 1;
	rep(i,N) cin >> v[i];
	v.push_back(0);

	vector<ll> upper(time + 1);
	vector<ll> V(time + 1);
	ll last = 0; 
	rep(i,N+1) {
		rep(j, t[i]) {
			upper[last  + 1 + j] = v[i];
			V[last  + 1 +j] = v[i];
		}
		last += t[i];
	}


	ll mostUpper = INF_LL;
	for(int i = time-1;i > -1;i--){
		if(V[i+1] != V[i]) {
			mostUpper = MIN(mostUpper+1,V[i+1]);
			upper[i] = MIN(upper[i],mostUpper);
		} else {
			mostUpper += 1;
			upper[i] = MIN(upper[i],mostUpper);
		}
	}

	double prespeed = 0;
	double speed = 0;
	double d = 0;
	for(int i = 1; i <= time - 1; i ++) {
		
		if(speed + 1 <= upper[i]) {
			d += (2.0*speed + 1.0) / 2.0;
			speed++;
		} else if(speed == upper[i]) {
			if(speed < V[i]){
				d+= 0.25 + speed;
			} else {
				d += speed;
			}
			// nop
		} else if(speed -1 == upper[i]) {
			d += (2.0*speed - 1.0) / 2.0;
			speed --;
		} else {
			exit(-1);
		}

	}
	outd(d)



	return 0;
}