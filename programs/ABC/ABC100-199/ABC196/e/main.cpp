#include <iostream> 
#include <vector> 
#include <unordered_map>
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
#define INF_LL 1LL << 50
#define MINF_LL - (1LL << 50)
#define MOD 998244353

#define MAX_N 2*100000+5


vector<ll> A,T;
ll N,Q;

ll f(ll x){
	for(ll n = 1; n <= N; n++) {
		if(T[n]==1){
			x= A[n]+x;
		}
		else if(T[n]==2){
			x= max(A[n],x);
		} if(T[n]==3){
			x= min(A[n],x);
		}  
	} 
	return x;
}

void solve() {
	cin >> N;
	A.resize(N+1);T.resize(N+1);
	rep(i,N){
		cin >> A[i+1] >> T[i+1];
	}
	ll x;
	cin >> Q;
	ll infans  = f(INF_LL);
	ll minfans = f(MINF_LL);
	if(infans == minfans){
		rep(i,Q){
			cin >> x;
			cout << infans <<endl;
		}
		return;
	}
	
	ll upper, lower =0;
	ll l= MINF_LL, r= INF_LL;
	while(l < r-1){
		ll mid = (l+r)/2;
		if(f(mid)==infans){
			r=mid;
		} else{
			l=mid;
		}
	}
	
	upper=l;
	
	l= MINF_LL, r= INF_LL;
	while(l < r-1){
		ll mid = (l+r)/2;
		if(f(mid)==minfans){
			l=mid;
		} else{
			r=mid;
		}
	}
	lower = r;
	
	ll lans =f(lower);
	
	rep(i,Q){
		cin	>> x;
		/*
		cout << x <<":";
		cout << f(N,x) <<":";
		*/
		if(x < lower){
			cout << minfans <<endl;
		} else if(x > upper) {
			cout << infans <<endl;
		} else {
			cout << lans + (x - lower) <<endl;
		}
	}
}


int main()
{
  solve();
	return 0;
}