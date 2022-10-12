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
	ll N;cin >> N;
	vector<ll>AO,AE;
	rep(i,N){
		ll a; cin >> a;
		if(a%2==0)AE.push_back(a);
		if(a%2==1)AO.push_back(a);
	}
	if(AE.size()==1&&AO.size()==1)cout<<-1<<endl;
	else{
		sort(AE.begin(),AE.end(),greater<ll>());
		sort(AO.begin(),AO.end(),greater<ll>());
		ll ans=0;
		if(AE.size()>=2)ans = max(ans,AE[0]+AE[1]);		
		if(AO.size()>=2)ans = max(ans,AO[0]+AO[1]);	
		cout << ans <<endl;
	}
	
	
	return 0;
}
