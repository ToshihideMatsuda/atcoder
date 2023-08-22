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
	
	ll h,w;cin>>h>>w;
	unordered_map<char,ll> R[h],C[w];
	rep(i,h)rep(j,w){
		char c;cin>>c;
		R[i][c]++;
		C[j][c]++;
	}
	
	while(true){
		vector<ll> remR,remC;
		rep(i,h){
			if(R[i].size()==1 && (*(R[i].begin())).second>1)
			  remR.push_back(i);
		}
		
		rep(i,w){
			if(C[i].size()==1 && (*(C[i].begin())).second>1)
			  remC.push_back(i);
		}
		
		
		if(remR.size()==0&&remC.size()==0) break;
		for(auto i:remR){
			ll c = (*(R[i].begin())).first;
			
			R[i].clear();
			rep(j,w){
				if(C[j].count(c)){
					if(C[j][c]==1){
						C[j].erase(c);
					}else{
						C[j][c]--;
					}
				}
			}
		}
		
		for(auto i:remC){
			if(C[i].size()==0)continue;
			ll c = (*(C[i].begin())).first;
			C[i].clear();
			rep(j,h){
				if(R[j].count(c)){
					if(R[j][c]==1){
						R[j].erase(c);
					}else{
						R[j][c]--;
					}
				}
			}
		}
		
	}
	ll ans=0;
	rep(i,h){
		for(auto idx =R[i].begin();idx!=R[i].end();++idx){
			ans+=(*idx).second;
		}
	}
	out(ans);
	
	return 0;
}
