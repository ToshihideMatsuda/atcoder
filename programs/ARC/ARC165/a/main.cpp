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
	ll a = 2*100000;
	EratosthenesPrime(2*100000);

	set<ll> primes;
	reps(i,1,a) if(prime[i]) primes.insert(i);


	ll T; cin >> T;
	while(T--) {
		ll N; cin >> N;
		ll isP = N;

		for(auto p: primes) if(N % p == 0) {
			while(N % p == 0) {
				N /= p;
			}
			break;
		}

		if(N == 1 || N == isP) { // N = p^k (1<= k)
			out("No")
		} else {
			out("Yes")
		}
	}
	return 0;
}