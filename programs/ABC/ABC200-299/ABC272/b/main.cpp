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

#define rep(i,n)     for(ll i = 0; i < n; i++ ) 
#define reps(i,m,n)  for(ll i = m; i < n; i++ ) 
#define MAX(a,b)   (a>b?a:b)
#define MAX3(a,b,c) max(a,MAX(b,c))
#define MIN(a,b)   (a<b?a:b)
#define MIN3(a,b,c) min(a,MIN(b,c))

#define INF 1 << 30
#define MINF -1*(1 << 30)
#define INF_LL 1LL << 60
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N 2*100000+5



int main()
{
	set<pair<ll,ll>> s;
	ll N,M;
	cin>> N >>M;
	
	rep(i,M){
		ll k;cin>>k;
		vector<ll> x(k);
		rep(j,k)cin >> x[j];
		
		rep(j,k-1)reps(ii,j+1,k)
		    s.insert({min(x[j],x[ii]),max(x[j],x[ii])});
	}
	if(s.size() ==N*(N-1)/2)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}
