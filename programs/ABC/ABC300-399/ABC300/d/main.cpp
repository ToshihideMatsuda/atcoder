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

//エラトステネスの篩、prime[i] = true -> 素数
bool prime[1000000+9];
void EratosthenesPrime(ll N){
  if(N == -1) N = 1000000+5;
  rep(i,1000000+9) prime[i] = true;
  prime[0] = false;
  prime[1] = false;
	for(ll i= 2; i<N+1;i++){
		for(ll j=2*i;j<N+1;j +=i){
			prime[j] =false;
		}
	}
}

int main()
{
	ll N; cin >> N;
	EratosthenesPrime(-1);


	ll ans = 0;
	ll sq = sqrtl(N);

	vector<ll> p;
	rep(i,sq+1)  if(prime[i]) {
		p.push_back(i); 
	}


	reps(i, 2, p.size()){ 
		ll c = p[i];
		if((p[0]*p[0])*p[1]*(c*c) <= N ){
			//少なくとも1つは解がある
			
			ll lb = 1, ub = i;
			while(ub-lb > 1) {
				ll mid = (lb+ub)/2;
				ll bq = p[mid];
				if( (p[0]*p[0]) * bq *c*c <= N) {
					lb = mid;
				} else {
					ub = mid;
				}
			}

			reps(j,1,lb+1) {
				ll b = p[j];

				ll lb = 0, ub = j;
				while(ub-lb > 1) {
					ll mid = (lb+ub)/2;
					ll aq = p[mid];
					if( aq*aq* b *c*c <= N) {
						lb = mid;
					} else {
						ub = mid;
					}
				}

				ans += (lb+1);
			}



		}
	}
	//78498
	out(ans)

	return 0;
}