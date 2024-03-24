#include "bits/stdc++.h"
using namespace std;
typedef long long ll;

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


int main()
{

	vector dp = vector(13,vector(10,0));
	dp[0][0] = 0;

	reps(i,1,13) {
		rep(j,10) if(i == 1 && j == 0) continue; 
		else {
			if(j == 0) {
				dp[i][j] = dp[i-1][j] + 
			} else {

			}
		}
	}


	
	ll Q;cin>>Q;
	while(Q--){
		ll x;cin>> x;
		
		
		vector<ll> keta;

		string ans="";
		ll base = 0;
		ll B = 1;
		if(1 <= x && x <= N) {
			out(to_string(neq[x-1]))
		} else if(x <= (1+M)*N) {
			out0(to_string(neq[((x-1)-N)/M]))
			out0(neq2[(x-N-1)%M])
			cout<<endl;
		} else if(x <= (1+M+M*M)*N) {
			out0(to_string(neq[((x-1)-(1+M)*N)/(M*M)]))
			out0(neq2[(((x-1)-(1+M)*N)/M)%M])
			out0(neq2[((x-1)-N)%M])
			cout<<endl;
		} else if(x <= (1+M+M*M+M*M*M)*N) {
			out0(to_string(neq[((x-1)-(1+M+M*M)*N)/(M*M*M)]))
			out0(neq2[((x-(1+M*M)*N-1)/M*M)%M])
			out0(neq2[((x-(1+M)*N-1)/M)%M])
			out0(neq2[(x-N-1)%M])

			cout<<endl;

		}
	}


	return 0;
}
