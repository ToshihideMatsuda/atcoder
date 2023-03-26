#include <bits/stdc++.h> 
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
	ll R, C; cin >> R >> C;
	char B[R+2][C+2];
	char D[R+2][C+2];
	rep(i,R+2) rep(j,C+2) {
		B[i][j] = 'x';
		D[i][j] = 'x';
	}
	reps(i,1,1+R) {
		reps(j,1,1+C) {
			cin >> B[i][j];
		}
	}

	reps(i,1,1+R) reps(j,1,1+C) {
		if('1' <= B[i][j] && B[i][j] <= '9') {

			ll l = B[i][j] - '0';
			reps(i2,1,1+R) reps(j2,1,1+C) {
				if(abs(i2 - i)  + abs(j2 -j) <= l ) {
					D[i2][j2] = '.';
				}
			}

		} else if(D[i][j] == 'x'){ //爆発前
			D[i][j] = B[i][j];
		}
	}

	reps(i,1,1+R){ reps(j,1,1+C) {
		out0(D[i][j])
		}
		cout << endl;
	}


	return 0;
}