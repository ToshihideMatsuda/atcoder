#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <stack>
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
#define out0(s) cout << s;

#define INF (1 << 30)
#define MINF -1*(1 << 30)
#define INF_LL (1LL << 60)
#define MINF_LL - (1LL << 60)
#define MOD 998244353

#define MAX_N (2*100000+5)



int main()
{
	ll n;cin>>n;
	vector<ll> x(n),l(n);
	rep(i,n)cin>>x[i];
	rep(i,n)cin>>l[i];
	vector<ll>s;
	rep(i,n)rep(j,n){
		s.push_back(x[i]+l[j]);
		s.push_back(x[i]-l[j]-1);
	}
	sort(s.begin(),s.end());
	
	bool area=false;
	ll begin=-1;
	ll ans=0;
	for(auto k:s){
		
		vector<ll> r(n);
		rep(i,n)r[i]=abs(x[i]-(k+1));
		
		sort(r.begin(),r.end());
		
		bool ok=true;
		rep(i,n)if((r[i]<=l[i])==false)ok=false;
		
		if(area==ok)continue;
		
		//cout<<k;
		if(area){
			ans+=k-begin;
			//cout<<":"<<k-begin+1<<"true->false";
			area=false;
		} else {
			begin=k;
			area=true;
			//cout<<":"<<0<<":false->true";
		}
		//cout<<endl;
		
	}
	out(ans);
	
	return 0;
}